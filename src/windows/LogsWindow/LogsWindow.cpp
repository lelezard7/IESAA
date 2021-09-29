#include "LogsWindow.h"
#include "ui_LogsWindow.h"


LogsWindow::
LogsWindow(QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::LogsWindow)
{
    ui_->setupUi(this);

    ui_->comboBox->addItem("Все");
    ui_->comboBox->addItem("Действия пользователя");
    ui_->comboBox->addItem("Редактирование");

    ui_->comboBox_2->addItem("Все");
    ui_->comboBox_2->addItem("Admin");
    ui_->comboBox_2->addItem("User_1");
    ui_->comboBox_2->addItem("User_2");
}

LogsWindow::
~LogsWindow()
{
    delete ui_;
}
