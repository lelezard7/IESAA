#include "CPFCreationWindow.h"
#include "ui_CPFCreationWindow.h"


CPFCreationWindow::
CPFCreationWindow(QWidget *parent)
    : QDialog(parent)
    , ui_(new Ui::CPFCreationWindow)
{
    ui_->setupUi(this);
    setFixedSize(size());

    ui_->comboBox->addItem("Текст");
    ui_->comboBox->addItem("Число");
    ui_->comboBox->addItem("Логический тип");
    ui_->comboBox->addItem("Валюта");
    ui_->comboBox->addItem("Дата");
    ui_->comboBox->addItem("Время");
    ui_->comboBox->addItem("Дата и время");

    ui_->comboBox_2->addItem("Значение");
    ui_->comboBox_2->addItem("Лист");
    ui_->comboBox_2->addItem("Список");
}

CPFCreationWindow::
~CPFCreationWindow()
{
    delete ui_;
}
