#include "GroupManagementWindow.h"
#include "ui_GroupManagementWindow.h"

#include "../ProfileCreationWindow/ProfileCreationWindow.h"


GroupManagementWindow::
GroupManagementWindow(QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::GroupManagementWindow)
{
    ui_->setupUi(this);

    ui_->comboBox->addItem("Все");
    ui_->comboBox->addItem("Утряняя группа");
    ui_->comboBox->addItem("Дневная группа: Взрослые");
    ui_->comboBox->addItem("Дневная группа: Дети");
    ui_->comboBox->addItem("Вечерняя группа");

    ui_->comboBox_2->addItem("Название");
    ui_->comboBox_2->addItem("Число участников");
    ui_->comboBox_2->addItem("Время занятия");
}

GroupManagementWindow::
~GroupManagementWindow()
{
    delete ui_;
}

void
GroupManagementWindow::
on_pushButton_4_clicked()
{
//    ProfileCreationWindow clientCreationWindow;
//    clientCreationWindow.exec();
}

void
GroupManagementWindow::
on_pushButton_6_clicked()
{
//    ProfileCreationWindow clientCreationWindow;
//    clientCreationWindow.exec();
}
