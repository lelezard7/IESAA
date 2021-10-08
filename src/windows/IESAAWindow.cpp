#include "IESAAWindow.h"
#include "ui_IESAAWindow.h"
#include <qalgorithms.h>
#include <algorithm>

#include "SettingsWindow/SettingsWindow.h"
#include "LogsWindow/LogsWindow.h"
#include "AboutIESAAWindow/AboutIESAAWindow.h"
#include "ProfileCreationWindow/ProfileCreationWindow.h"
#include "GroupManagementWindow/GroupManagementWindow.h"
#include "StatisticsWindow/StatisticsWindow.h"


#include "../IProfile.h"


#define ProfileCategory_Clients   "Клиенты"
#define ProfileCategory_Staff     "Персонал"
#define ProfileCategory_Groups    "Группы"






IESAAWindow::
IESAAWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui_(new Ui::IESAAWindow)
{
    ui_->setupUi(this);

    defaultFieldDataBase_.createAssociation(ProfileCategory_Clients, new FieldDataBase);
    defaultFieldDataBase_.createAssociation(ProfileCategory_Staff, new FieldDataBase);
    defaultFieldDataBase_.createAssociation(ProfileCategory_Groups, new FieldDataBase);

    profileDataBaseManager_.createAssociation(ProfileCategory_Clients, new ProfileDataBase);
    profileDataBaseManager_.createAssociation(ProfileCategory_Staff, new ProfileDataBase);
    profileDataBaseManager_.createAssociation(ProfileCategory_Groups, new ProfileDataBase);

    initNamesSets();
    initDefaultFieldsWidgets();

    //   === Для демонстрации клиенту ===

    ui_->infoBar->setText("Пользователь: Артемий | Права: Администратор");

    ui_->mainTable->setColumnCount(11);
    ui_->mainTable->setRowCount(30);

    QStringList columnTitles;
    columnTitles << "ID" << "Артикул" << "Категория" << "Наименование" << "Цена (руб.)"
                 << "Кол-во (шт.)" << "Материал" << "Цвет" << "Размер" << "Вес (кг.)" << "Пометка";

    ui_->mainTable->setHorizontalHeaderLabels(columnTitles);

    QStringList content;
    int row = 0;
    int column = 0;

    auto fillTableRow = [this, row, column](const QString& it) mutable {
        QTableWidgetItem* tableItem = new QTableWidgetItem;
        tableItem->setData(0, it);
        ui_->mainTable->setItem(row, column, tableItem);
        ++column;
    };

    content << "11" << "MP002XM1GYPS" << "Пиджак" << "Пиджак" << "7 790" << "10" << "Шерсть"
            << "Серый" << "50/176" << "0.015" << "Не заказывать больше";
    std::for_each(content.begin(), content.end(), fillTableRow);
//    ++row;

    content << "20" << "AD002EMKGHW4" << "Футболка спортивная" << "Футболка спортивная TABELA 18 JSY"
            << "1 999" << "3" << "Полиэстер" << "Черный" << "M" << "0.005" << "";
    std::for_each(content.begin(), content.end(), fillTableRow);
//    ++row;

    content << "4" << "15604376" << "Грунт" << "Грунт универсальный «Просто»" << "222" << "44" << ""
            << "" << "" << "19.07" << "";
    std::for_each(content.begin(), content.end(), fillTableRow);


    ui_->mainTable->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);

    menu_ = new QMenu;
    menu_->addAction("Редактировать");
    menu_->addAction("Копировать");
    menu_->addAction("Вырезать");
    menu_->addAction("Вставить");
    connect(ui_->mainTable, &QMenu::customContextMenuRequested, this, &IESAAWindow::fff);


//    FIELD_DATA_TYPE(int, int) ddddd;
//    ddddd.addData(3);

//    qDebug() << ddddd.isValid(0);
//    qDebug() << ddddd.isValid(909000);
//    qDebug() << ddddd.format(55);

//    qDebug() << "---------------------";

//    FIELD_DATA_TYPE(QDate, int) ddddd2;
//    ddddd2.addData({2021, 11, 13});

//    qDebug() << ddddd2.isValid({1, 1, 1});
//    qDebug() << ddddd2.isValid({1, 1, 28});


//    IField<int, int> field;
//    field.addData(&ddddd);

//    IField<QDate, int> field2;
//    field2.addData(&ddddd2);

//    IProfile profile;
//    profile.addField(field);
//    profile.addField(field2);

//    auto a = profile.getField<int, int>(FIELD_DATA_TYPE_NAME(int, int));
//    auto b = profile.getField<QDate, int>(FIELD_DATA_TYPE_NAME(QDate, int));







    //    auto ff = fieldToValue<int>(field, 0);
}

IESAAWindow::
~IESAAWindow()
{
    delete ui_;
}

void
IESAAWindow::
on_action_Settings_triggered()
{
    SettingsWindow settingsWindow(this);
    settingsWindow.exec();
}

void
IESAAWindow::
on_action_Log_triggered()
{
    LogsWindow logsWindow(this);
    logsWindow.exec();
}

void
IESAAWindow::
on_action_AboutIESAA_triggered()
{
    AboutIESAAWindow aboutIESAAWindow(this);
    aboutIESAAWindow.exec();
}

void
IESAAWindow::
on_action_NewClient_triggered()
{
    ProfileCreationWindow clientCreationWindow(
                namesSetsManager_,
                defaultFieldsCreator_,
                defaultFieldDataBase_.getValue(ProfileCategory_Clients),
                ID_Null,
                profileDataBaseManager_.getValue(ProfileCategory_Clients),
                this);
    clientCreationWindow.exec();
}

void
IESAAWindow::
on_action_NewGroup_triggered()
{
    qDebug() << "Field count: " << profileDataBaseManager_.getValue(ProfileCategory_Groups)->size();

    ProfileCreationWindow clientCreationWindow(
                namesSetsManager_,
                defaultFieldsCreator_,
                defaultFieldDataBase_.getValue(ProfileCategory_Groups),
                1,
                profileDataBaseManager_.getValue(ProfileCategory_Groups),
                this);
    clientCreationWindow.exec();
    qDebug() << "Field count: " << profileDataBaseManager_.getValue(ProfileCategory_Groups)->size();
}

void
IESAAWindow::
on_action_GroupManagement_triggered()
{
    GroupManagementWindow groupManagementWindow(this);
    groupManagementWindow.exec();
}

void
IESAAWindow::
on_action_Staff_triggered()
{
    staffWindow_ = new StaffWindow(this);
    staffWindow_->setWindowFlag(Qt::Window, true);
    staffWindow_->show();
}

void
IESAAWindow::
on_action_Statistics_triggered()
{
    StatisticsWindow statisticsWindow(this);
    statisticsWindow.exec();
}

void
IESAAWindow::
fff(const QPoint &pos)
{
    menu_->popup(mapToGlobal(pos));
    ui_->infoBar->setText("dddddd");
}

void
IESAAWindow::
initNamesSets()
{
    namesSetsManager_.addNamesSet("Текст",          "Значение");
    namesSetsManager_.addNamesSet("Текст",          "Лист");
    namesSetsManager_.addNamesSet("Число",          "Значение");
    namesSetsManager_.addNamesSet("Логический тип", "Значение");
    namesSetsManager_.addNamesSet("Валюта",         "Значение");
    namesSetsManager_.addNamesSet("Время",          "Значение");
    namesSetsManager_.addNamesSet("Дата",           "Значение");
    namesSetsManager_.addNamesSet("Дата и время",   "Значение");
}

void
IESAAWindow::
initDefaultFieldsWidgets()
{
    QLineEdit* le = new QLineEdit();
    IFieldWidget* widget = new FieldLineEdit;
    widget->setWidget(le);

    defaultFieldsCreator_.createAssociation(NamesSetsManager::findSetName("Текст", "Значение"), widget);
}
