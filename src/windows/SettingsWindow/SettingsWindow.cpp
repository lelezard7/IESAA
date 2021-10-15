#include "SettingsWindow.h"
#include "ui_SettingsWindow.h"

#include "../PFCreationWindow/PFCreationWindow.h"

#include <QFontDialog>
#include <QColorDialog>

















SettingsWindow::
SettingsWindow(
        NamesSetsManager& namesSetsManager,
        DefaultFieldsCreator* defaultFieldsCreator,
        DefaultFieldDataBase* defaultFieldDataBase,
        QWidget* parent)
    : QDialog              (parent)
    , ui_                  (new Ui::SettingsWindow)
    , namesSetsManager_    (namesSetsManager)
    , defaultFieldsCreator_(defaultFieldsCreator)
    , defaultFieldDataBase_(defaultFieldDataBase)
{
    ui_->setupUi(this);

    fieldsSettingsHelper_.setInfoLabel(ui_->label_2);
    fieldsSettingsHelper_.setTableWidget(ui_->tableWidget);
    fieldsSettingsHelper_.setDefaultFieldDataBase(defaultFieldDataBase_);

    fieldsSettingsHelper_.addColumn("Видимость");
    fieldsSettingsHelper_.addColumn("Название");
    fieldsSettingsHelper_.addColumn("Значение");

    ui_->tableWidget->horizontalHeader()->resizeSection(0, 80);
    ui_->tableWidget->horizontalHeader()->resizeSection(1, 200);
    ui_->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeMode::Stretch);

    for (size_t i = 0; i < defaultFieldDataBase->size(); ++i) {
        ui_->comboBox->addItem(defaultFieldDataBase->getName(i));
    }

    fieldsSettingsHelper_.switchTo(defaultFieldDataBase->getName(0));


//    ui_->comboBox->addItem("Профиль клиента");
//    ui_->comboBox->addItem("Профиль группы");
//    ui_->comboBox->addItem("Профиль сотрудника");

//    ui_->comboBox_2->addItem("Все");
//    ui_->comboBox_2->addItem("Программа");
//    ui_->comboBox_2->addItem("Главная таблица: Заголовки");
//    ui_->comboBox_2->addItem("Главная таблица: Нумерация");
//    ui_->comboBox_2->addItem("Главная таблица: Тело");
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
    PFCreationWindow pf_creationWindow(
                createFieldReceiver(fieldsSettingsHelper_, FieldsSettingsHelper::addFieldToDefaultFields),
                this);
    pf_creationWindow.exec();
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

void
SettingsWindow::
on_comboBox_currentTextChanged(const QString &arg1)
{
    fieldsSettingsHelper_.switchTo(arg1);
}
