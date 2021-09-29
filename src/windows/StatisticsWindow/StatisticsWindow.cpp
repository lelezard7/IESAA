#include "StatisticsWindow.h"
#include "ui_StatisticsWindow.h"


StatisticsWindow::
StatisticsWindow(QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::StatisticsWindow)
{
    ui_->setupUi(this);

    ui_->comboBox_2->addItem("Прибыль");
    ui_->comboBox_2->addItem("Новых клиентов");
    ui_->comboBox_2->addItem("Количество занятий");
}

StatisticsWindow::
~StatisticsWindow()
{
    delete ui_;
}
