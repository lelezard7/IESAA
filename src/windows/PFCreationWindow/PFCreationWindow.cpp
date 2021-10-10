#include "PFCreationWindow.h"
#include "ui_PFCreationWindow.h"











PFCreationWindow::
PFCreationWindow(
        NamesSetsManager& namesSetsManager,
        DefaultFieldsCreator& defaultFieldsCreator,
        FieldReceiver fieldReceiver,
        QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::PFCreationWindow)
    , namesSetsManager_(namesSetsManager)
    , defaultFieldsCreator_(defaultFieldsCreator)
    , sendField(fieldReceiver)
{
    ui_->setupUi(this);
    setFixedSize(size());

    pf_creationHelper_.setComboBoxes(ui_->comboBox, ui_->comboBox_2);
    pf_creationHelper_.setNamesSetsManager(&namesSetsManager_);
    pf_creationHelper_.setDefaultFieldsCreator(&defaultFieldsCreator_);

    pf_creationHelper_.refreshUi();
}

PFCreationWindow::
~PFCreationWindow()
{
    delete ui_;
}

void
PFCreationWindow::
on_buttonBox_accepted()
{
////    static_cast<QLineEdit*>(fieldAssoc_.widget(fff)->getWidget())->setText(ui_->lineEdit->text());
    Field* field = new Field;

    IFieldWidget* fieldWidget = pf_creationHelper_.copyCurrentFieldWidget();
    if (!fieldWidget) {
        delete field;
        delete fieldWidget;
        return;
    }

    field->setWidget(fieldWidget);
    field->setName(ui_->lineEdit->text());


    if (!sendField(field))
        delete field;
}



void PFCreationWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    pf_creationHelper_.switchTo(arg1);
}

