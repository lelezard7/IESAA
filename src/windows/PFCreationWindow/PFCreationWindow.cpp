#include "PFCreationWindow.h"
#include "ui_PFCreationWindow.h"


#define addAssociation(Name, Id) \
    fieldCreator.addAssociation(Name, Id); \
    ui_->comboBox->addItem(Name);


PFCreationWindow::
PFCreationWindow(IProfile* profile, QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::PFCreationWindow)
    , profile_(profile)
{
    ui_->setupUi(this);
    setFixedSize(size());

    addAssociation("Число", DT_Int);
    addAssociation("Дата", DT_Data);

//    ui_->comboBox->addItem("Текст");
//    ui_->comboBox->addItem("Логический тип");
//    ui_->comboBox->addItem("Валюта");
//    ui_->comboBox->addItem("Время");
//    ui_->comboBox->addItem("Дата и время");

//    ui_->comboBox_2->addItem("Значение");
//    ui_->comboBox_2->addItem("Лист");
//    ui_->comboBox_2->addItem("Список");
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
//    FIELD_DATA_TYPE(int, QSpinBox)* data = new FIELD_DATA_TYPE(int, QSpinBox);
////    data->refresh();  //TODO: Error
//    data->addData(3);


//    IField<int, QSpinBox>* field = new IField<int, QSpinBox>;
//    field->setName(ui_->lineEdit->text().toStdString());
//    field->addData(data);

    fieldCreator.addField(ui_->lineEdit->text(), profile_, ui_->comboBox->itemText(ui_->comboBox->currentIndex()));
}

