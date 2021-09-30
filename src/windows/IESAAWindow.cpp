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
#include "../IField.h"


DEFINE_FIELD_DATA_TYPE(
        int,
        Func_Format(int), {
            return data;
        },
        Func_IsValid(int), {
            return !data;
        }
        )

DEFINE_FIELD_DATA_TYPE(
        QDate,
        Func_IsValid(QDate), {
            return data == QDate(1, 1, 1);
        },
        Func_Format(QDate), {
            return data == QDate(3, 3, 3);
        }
        )



IESAAWindow::
IESAAWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui_(new Ui::IESAAWindow)
{
    ui_->setupUi(this);

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



    FIELD_DATA_TYPE(int) ddddd;
    ddddd.addData(3);

    qDebug() << ddddd.isValid(0);
    qDebug() << ddddd.isValid(909000);
    qDebug() << ddddd.format(55);

    qDebug() << "---------------------";

    FIELD_DATA_TYPE(QDate) ddddd2;
    ddddd2.addData({2021, 11, 13});

    qDebug() << ddddd2.isValid({1, 1, 1});
    qDebug() << ddddd2.isValid({1, 1, 28});


    IField field;
    field.addData(ddddd);
    field.addData(ddddd2);

    auto fff = field.getData(0);
    auto a1 = CAST::ConvertToFIELD_DATA_TYPE_int(fff);

    auto fff2 = field.getData(1);
    auto a2 = CAST::ConvertToFIELD_DATA_TYPE_QDate(fff2);








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
    ProfileCreationWindow clientCreationWindow(this);
    clientCreationWindow.exec();
}

void
IESAAWindow::
on_action_NewGroup_triggered()
{
    ProfileCreationWindow clientCreationWindow(this);
    clientCreationWindow.exec();
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
