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

//    ui_->lineEdit_FieldName->setText(field_->getName());
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

    pfCreationHelper_.setComboBoxes(ui_->comboBox_DataType, ui_->comboBox_RecFormat);
    pfCreationHelper_.setNamesSetsManager(getNamesSetsManager());
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

    Field* field = new Field;

    IFieldWidget* fieldWidget = pfCreationHelper_.copyCurrentFieldWidget();
    if (!fieldWidget) {
        delete field;
        return;
    }

    field->setWidget(fieldWidget);
    field->setName(ui_->lineEdit_FieldName->text());

    AppError appError = sendField(field);
    if (appError != ErrCode_No) {
        messageBar_.setErrorMessage(appError.description);                   //TODO: доделать.
        delete field;
        return;
    }

    accept();
}




















//PFCreationWindow::
//PFCreationWindow(
//        NamesSetsManager& namesSetsManager,
//        DefaultFieldsCreator& defaultFieldsCreator,
//        FieldReceiver fieldReceiver,
//        QWidget* parent)
//    : QDialog(parent)
//    , ui_(new Ui::PFCreationWindow)
//    , namesSetsManager_(namesSetsManager)
//    , defaultFieldsCreator_(defaultFieldsCreator)
//    , sendField(fieldReceiver)
//{
//    ui_->setupUi(this);
//    setFixedSize(size());

//    pf_creationHelper_.setComboBoxes(ui_->comboBox, ui_->comboBox_2);
//    pf_creationHelper_.setNamesSetsManager(&namesSetsManager_);
//    pf_creationHelper_.setDefaultFieldsCreator(&defaultFieldsCreator_);

//    pf_creationHelper_.refreshUi();
//}

//PFCreationWindow::
//~PFCreationWindow()
//{
//    delete ui_;
//}

//void
//PFCreationWindow::
//on_buttonBox_accepted()
//{
//    Field* field = new Field;

//    IFieldWidget* fieldWidget = pf_creationHelper_.copyCurrentFieldWidget();
//    if (!fieldWidget) {
//        delete field;
//        delete fieldWidget;
//        return;
//    }

//    field->setWidget(fieldWidget);
//    field->setName(ui_->lineEdit->text());


//    if (!sendField(field))
//        delete field;
//}

//void PFCreationWindow::on_comboBox_currentTextChanged(const QString &arg1)
//{
//    pfCreationHelper_.switchTo(arg1);
//}
