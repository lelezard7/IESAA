#include "PFCreationWindow.h"
#include "ui_PFCreationWindow.h"

#define EM_LineEditFieldName_IsEmpty   "Нужно указать название данного поля!"
#define EM_ComboBoxDataType_NotSet     "Нужно выбрать тип данных данного поля!"
#define EM_ComboBoxRecFormat_NotSet    "Нужно выбрать формат записи данного поля!"


PFCreationWindow::
PFCreationWindow(FieldReceiver fieldReceiver, QWidget* parent)
    : QDialog  (parent)
    , ui_      (new Ui::PFCreationWindow)
    , sendField(fieldReceiver)
    , field_   (nullptr)
{ init(); }

PFCreationWindow::
PFCreationWindow(Field* field, QWidget* parent)
    : QDialog  (parent)
    , ui_      (new Ui::PFCreationWindow)
    , sendField(nullptr)
    , field_   (field)
{
    init();

    ui_->lineEdit_FieldName->setText(field_->getName());

    for (size_t i = 0; i < assocs_.size(); ++i) {
        if (assocs_.getValue(*assocs_.getName(i)) == GetDTID(field->getWidgetId()))
            ui_->comboBox_DataType->setCurrentText(*assocs_.getName(i));
    }

    for (size_t i = 0; i < assocs_.size(); ++i) {
        if (assocs_.getValue(*assocs_.getName(i)) == GetRFID(field->getWidgetId()))
            ui_->comboBox_RecFormat->setCurrentText(*assocs_.getName(i));
    }
}

PFCreationWindow::
~PFCreationWindow()
{ delete ui_; }

void
PFCreationWindow::
init()
{
    ui_->setupUi(this);
    setWindowTitle(APP_NAME " | Создание поля профиля");
    setFixedSize(size());


    namesSetsManager_.addNamesSet("Текст",          "Значение");
    namesSetsManager_.addNamesSet("Текст",          "Лист");
    namesSetsManager_.addNamesSet("Логический тип", "Значение");
    namesSetsManager_.addNamesSet("Время",          "Значение");
    namesSetsManager_.addNamesSet("Дата",           "Значение");
    namesSetsManager_.addNamesSet("Дата и время",   "Значение");


    assocs_.createAssociation("Текст",            DTID_Text);
    assocs_.createAssociation("Логический тип",   DTID_Boolean);
    assocs_.createAssociation("Время",            DTID_Time);
    assocs_.createAssociation("Дата",             DTID_Date);
    assocs_.createAssociation("Дата и время",     DTID_DateTime);

    assocs_.createAssociation("Значение",   RFID_Value);
    assocs_.createAssociation("Лист",       RFID_Sheet);


    pfCreationHelper_.setComboBoxes(ui_->comboBox_DataType, ui_->comboBox_RecFormat);
    pfCreationHelper_.setNamesSetsManager(&namesSetsManager_);
    pfCreationHelper_.setAssocs(&assocs_);
    pfCreationHelper_.setDefaultFieldsCreator(getDefaultFieldsCreator());
    pfCreationHelper_.refreshUi();

    messageBar_.setMessageBar(ui_->label_MessageBar);
    messageBar_.reset();

    connect(ui_->pushButton_Cancel, &QPushButton::clicked, this, &PFCreationWindow::reject);
}

void
PFCreationWindow::
on_lineEdit_FieldName_textChanged(const QString&)
{
    if (messageBar_.getMessage() != EM_ComboBoxDataType_NotSet &&
        messageBar_.getMessage() != EM_ComboBoxRecFormat_NotSet)
        messageBar_.resetMessage();
}

void
PFCreationWindow::
on_comboBox_DataType_currentTextChanged(const QString& currentText)
{
    messageBar_.resetMessage(EM_ComboBoxDataType_NotSet);
    messageBar_.resetMessage(EM_ComboBoxRecFormat_NotSet);
    pfCreationHelper_.switchTo(currentText);
}

void
PFCreationWindow::
on_comboBox_RecFormat_currentTextChanged(const QString&)
{ messageBar_.resetMessage(EM_ComboBoxRecFormat_NotSet); }

void
PFCreationWindow::
on_pushButton_Apply_clicked()
{
    if (ui_->lineEdit_FieldName->text() == "") {
        messageBar_.setErrorMessage(EM_LineEditFieldName_IsEmpty);
        return;
    }

    if (ui_->comboBox_DataType->currentText() == "") {
        messageBar_.setErrorMessage(EM_ComboBoxDataType_NotSet);
        return;
    }

    if (ui_->comboBox_RecFormat->currentText() == "") {
        messageBar_.setErrorMessage(EM_ComboBoxRecFormat_NotSet);
        return;
    }

    if (!field_) {
        Field* field = new Field;

        IFieldWidget* fieldWidget = pfCreationHelper_.copyCurrentFieldWidget();
        if (!fieldWidget) {
            delete field;
            return;
        }

        field->setWidget(fieldWidget);
        field->setName(ui_->lineEdit_FieldName->text());
        field->setWidgetId(pfCreationHelper_.getWidgetId());

        AppError appError = sendField(field);
        if (appError != ErrCode_No) {
            messageBar_.setErrorMessage(appError.description);
            delete field;
            return;
        }

        accept();
    }

//    field_->getWidget()->
}
