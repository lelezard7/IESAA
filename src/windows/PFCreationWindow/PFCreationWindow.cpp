#include "PFCreationWindow.h"
#include "ui_PFCreationWindow.h"


template<class T>
struct A
{
    T value_;
};

struct B : public A<int>
{

};

PFCreationWindow::
PFCreationWindow(QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::PFCreationWindow)
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

PFCreationWindow::
~PFCreationWindow()
{
    delete ui_;
}
