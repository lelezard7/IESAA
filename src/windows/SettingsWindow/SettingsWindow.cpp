#include "SettingsWindow.h"
#include "ui_SettingsWindow.h"

#include "../PFCreationWindow/PFCreationWindow.h"

#include <QFontDialog>
#include <QColorDialog>

SettingsWindow::
SettingsWindow(QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::SettingsWindow)
{
    ui_->setupUi(this);

    ui_->comboBox->addItem("Профиль клиента");
    ui_->comboBox->addItem("Профиль группы");
    ui_->comboBox->addItem("Профиль сотрудника");

    ui_->comboBox_2->addItem("Все");
    ui_->comboBox_2->addItem("Программа");
    ui_->comboBox_2->addItem("Главная таблица: Заголовки");
    ui_->comboBox_2->addItem("Главная таблица: Нумерация");
    ui_->comboBox_2->addItem("Главная таблица: Тело");
}

SettingsWindow::
~SettingsWindow()
{
    delete ui_;
}

void
SettingsWindow::
on_pushButton_clicked()
{
    PFCreationWindow cpf_creationWindow(nullptr, this);
    cpf_creationWindow.exec();
}

void
SettingsWindow::
on_toolButton_clicked()
{
    QFontDialog fontDialog;
    bool isOk;
    fontDialog.getFont(&isOk);
}

void
SettingsWindow::
on_toolButton_2_clicked()
{
    QColorDialog colorDialog;
    colorDialog.getColor();
}
