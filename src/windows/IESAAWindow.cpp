#include "IESAAWindow.h"
#include "ui_IESAAWindow.h"
#include <qalgorithms.h>
#include <algorithm>
#include <QSpacerItem>
#include <QScrollArea>

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




void
TabWidgetManager::
setTabWidget(QTabWidget* tabWidget)
{
    tabWidget_ = tabWidget;
//    informant_.set
}

QTabWidget*
TabWidgetManager::
getTabWidget() const
{ return tabWidget_; }

Informant*
TabWidgetManager::
getInformant()
{ return &informant_; }

void
TabWidgetManager::
showHide()
{
    if (tabWidget_->isHidden()) {
        tabWidget_->show();
        if (tabWidget_->currentWidget()->objectName() == "tab_2")

        return;
    }

    tabWidget_->hide();
}













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

    mainTableHelper_.setTableWidget(ui_->mainTable);
    mainTableHelper_.setProfileDataBaseManager(&profileDataBaseManager_);

    informant_.setPushButton(ui_->pushButton);
    informant_.setScrollAreaWidgetContents(ui_->scrollAreaWidgetContents);

    ui_->tabWidget->hide();

    QList<int> currentSizes = ui_->splitter->sizes();
    currentSizes[0] = 1000;
    currentSizes[1] = 300;
    ui_->splitter->setSizes(currentSizes);

    //   === Для демонстрации клиенту ===

    ui_->infoBar->setText("Пользователь: Артемий | Права: Администратор");

//    ui_->mainTable->setColumnCount(11);
//    ui_->mainTable->setRowCount(30);

//    QStringList columnTitles;
//    columnTitles << "ID" << "Артикул" << "Категория" << "Наименование" << "Цена (руб.)"
//                 << "Кол-во (шт.)" << "Материал" << "Цвет" << "Размер" << "Вес (кг.)" << "Пометка";

//    ui_->mainTable->setHorizontalHeaderLabels(columnTitles);

//    QStringList content;
//    int row = 0;
//    int column = 0;

//    auto fillTableRow = [this, row, column](const QString& it) mutable {
//        QTableWidgetItem* tableItem = new QTableWidgetItem;
//        tableItem->setData(0, it);
//        ui_->mainTable->setItem(row, column, tableItem);
//        ++column;
//    };

//    content << "11" << "MP002XM1GYPS" << "Пиджак" << "Пиджак" << "7 790" << "10" << "Шерсть"
//            << "Серый" << "50/176" << "0.015" << "Не заказывать больше";
//    std::for_each(content.begin(), content.end(), fillTableRow);
////    ++row;

//    content << "20" << "AD002EMKGHW4" << "Футболка спортивная" << "Футболка спортивная TABELA 18 JSY"
//            << "1 999" << "3" << "Полиэстер" << "Черный" << "M" << "0.005" << "";
//    std::for_each(content.begin(), content.end(), fillTableRow);
////    ++row;

//    content << "4" << "15604376" << "Грунт" << "Грунт универсальный «Просто»" << "222" << "44" << ""
//            << "" << "" << "19.07" << "";
//    std::for_each(content.begin(), content.end(), fillTableRow);


//    ui_->mainTable->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);

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
    SettingsWindow settingsWindow(
                namesSetsManager_,
                &defaultFieldsCreator_,
                &defaultFieldDataBase_,
                this);
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

    mainTableHelper_.refreshClients();
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
                ID_Null,
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
//    NamesSetsManager* namesSetsManager = getNamesSetsManager();

//    namesSetsManager->addNamesSet("Текст",          "Значение");
//    namesSetsManager->addNamesSet("Текст",          "Лист");
//    namesSetsManager->addNamesSet("Логический тип", "Значение");
//    namesSetsManager->addNamesSet("Время",          "Значение");
//    namesSetsManager->addNamesSet("Дата",           "Значение");
//    namesSetsManager->addNamesSet("Дата и время",   "Значение");
}

void
IESAAWindow::
initDefaultFieldsWidgets()
{
//    DefaultFieldsCreator* defaultFieldsCreator = getDefaultFieldsCreator();

//    QLineEdit* lineEdit = new QLineEdit;
//    IFieldWidget* fieldLineEdit = new FieldLineEdit;
//    fieldLineEdit->setWidget(lineEdit);
//    defaultFieldsCreator->createAssociation(WID_FieldLineEdit, fieldLineEdit);

//    ExtTextEdit* textEdit = new ExtTextEdit;
//    IFieldWidget* fieldTextEdit = new FieldTextEdit;
//    fieldTextEdit->setWidget(textEdit);
//    defaultFieldsCreator->createAssociation(WID_FieldTextEdit, fieldTextEdit);

//    QCheckBox* checkBox = new QCheckBox;
//    IFieldWidget* fieldCheckBox = new FieldCheckBox;
//    fieldCheckBox->setWidget(checkBox);
//    defaultFieldsCreator->createAssociation(WID_FieldCheckBox, fieldCheckBox);

//    QDateEdit* dateEdit = new QDateEdit;
//    dateEdit->setCalendarPopup(true);
//    IFieldWidget* fieldDateEdit = new FieldDateEdit;
//    fieldDateEdit->setWidget(dateEdit);
//    defaultFieldsCreator->createAssociation(WID_FieldDateEdit, fieldDateEdit);

//    QDateTimeEdit* dateTimeEdit = new QDateTimeEdit;
//    dateTimeEdit->setCalendarPopup(true);
//    dateTimeEdit->setDisplayFormat("dd.MM.yyyy HH:mm:ss");
//    IFieldWidget* fieldDateTimeEdit = new FieldDateTimeEdit;
//    fieldDateTimeEdit->setWidget(dateTimeEdit);
//    defaultFieldsCreator->createAssociation(WID_FieldDateTimeEdit, fieldDateTimeEdit);

//    QTimeEdit* timeEdit = new QTimeEdit;
//    timeEdit->setCalendarPopup(true);
//    timeEdit->setDisplayFormat("HH:mm:ss");
//    IFieldWidget* fieldTimeEdit = new FieldTimeEdit;
//    fieldTimeEdit->setWidget(timeEdit);
//    defaultFieldsCreator->createAssociation(WID_FieldTimeEdit, fieldTimeEdit);
}

void
IESAAWindow::
on_comboBox_currentTextChanged(const QString &arg1)
{
    informant_.sendInfoMessage("Езал грека через реку, видит грека в реке рак."
                               "Сунул грека руку в реку, рак за руку греку цап.");
    informant_.sendInfoMessage("dfgdfgdfgdfgdf");
    informant_.sendInfoMessage("dfgdfgdfgdfgdf2");
//    mainTableHelper_.clear();
//    mainTableHelper_.refresh("Клиенты");

//    if (arg1 == "Клиенты")
//        mainTableHelper_.clear();
}


void
IESAAWindow::
on_pushButton_2_clicked(bool checked)
{
    if (checked) {
        ui_->tabWidget->show();
    }
    else {
        ui_->tabWidget->hide();
    }
}

void
IESAAWindow::
on_action_triggered()
{
    SubscriptionWindow subscriptionWindow(this);
    subscriptionWindow.exec();
}

void
IESAAWindow::
on_pushButton_clicked(bool checked)
{
    if (checked) {
        ui_->tabWidget->show();
    }
    else {
        ui_->tabWidget->hide();
    }
}

void
IESAAWindow::
on_tabWidget_currentChanged(int index)
{
    if (index == 1)
        informant_.setViewed(true);
}


class MyLineEdit;

class A : public QWidget
{
    int a_;

public:
    A() : a_(0) {};
    virtual ~A() {};

    void setA(int a) {
        a_ = a;
    };

    void fff() {
        qDebug() << "======== " << a_;
    };

    MyLineEdit* getThis() {
        MyLineEdit* reff = reinterpret_cast<MyLineEdit*>(this);
        return reff;
    };

};






class Ac
{
public:
    Ac() {
        qDebug() << "Constructor Ac";
    };

    virtual ~Ac() {
        qDebug() << "Destructor Ac";
    };

    virtual void foo() {
        qDebug() << "Foo Ac";
    };
};

class Bc : public Ac
{
public:
    Bc() {
        qDebug() << "Constructor Bc";
    };

    virtual ~Bc() {
        qDebug() << "Destructor Bc";
    };

    void foo() {
        qDebug() << "Foo Bc";
    };
};

class Cc : public Bc
{
public:
    Cc() {
        qDebug() << "Constructor Cc";
    };

    virtual ~Cc() {
        qDebug() << "Destructor Cc";
    };

    void foo() {
        qDebug() << "Foo Cc";
    };
};




void
IESAAWindow::
on_pushButton_5_clicked()
{
    Ac* ffff = new Cc;
    ffff->foo();
    delete ffff;



    ui_->mainTable->setColumnCount(10);
    ui_->mainTable->setRowCount(10);

    Field* field = new Field;
    field->setName("Test");

    StyleSheetCreator ssc;
    StyleSheetRule r = ssc.getStyleSheetRule();

    QString dd = ssc;
//    QString dd2 = r;


//    QWidget* w = new MyLineEdit;
//    dynamic_cast<MyIExtention*>(w)->setParentField(field);
//    dynamic_cast<QLineEdit*>(w)->setText("dddd");
//    ui_->mainTable->setCellWidget(0, 0, w);

//    QWidget* o = ui_->mainTable->cellWidget(0, 0);
//    qDebug() << dynamic_cast<MyIExtention*>(o)->getParentField()->getName();
//    qDebug() << dynamic_cast<MyIExtention*>(o)->getWidgetText();
//    qDebug() << dynamic_cast<QLineEdit*>(o)->text();








//    ui_->mainTable->setColumnCount(10);
//    ui_->mainTable->setRowCount(10);

//    Field field;
//    field.setName("Test");

//    QWidget* f = new MyLineEdit;
//    f->setParentField(&field);

//    MyLineEdit* d = static_cast<MyLineEdit*>(f);
//    d->setText("ddddddddd");

//    ui_->mainTable->setCellWidget(0, 0, f);
//    QWidget* o = ui_->mainTable->cellWidget(0, 0);
//    IMyLineEdit* d7 = static_cast<IMyLineEdit*>(o);
//    qDebug() << d7->getParentField()->getName();
//    qDebug() << static_cast<QLineEdit*>(o)->text();




//    Field field;
//    field.setName("Test");

//    QWidget* f = new MyLineEdit;

//    IExtWidget* d = static_cast<IExtWidget*>(f);
//    d->setParentField(&field);

//    IExtWidget* d2 = static_cast<IExtWidget*>(f);
//    qDebug() << d2->getParentField()->getName();




//    QWidget* d = static_cast<QLineEdit*>(new MyLineEdit);
//    QWidget* d = new MyLineEdit;

//    QLineEdit* a2 = reinterpret_cast<QLineEdit*>(d);
//    a2->setText("00000000000");
//    qDebug() << a2->text();

//    A* f = reinterpret_cast<A*>(d);
//    f->setA(3);
//    f->fff();
//    f->setA(6);
//    f->fff();

//    qDebug() << f->getThis()->text();






//    QWidget* d = new MyLineEdit;
//    MyLineEdit* f = reinterpret_cast<MyLineEdit*>(d);
//    f->setA(3);
//    f->setText("--------------------------");
//    A* a = reinterpret_cast<A*>(d);
//    QLineEdit* a2 = reinterpret_cast<QLineEdit*>(a->getThis());
//    qDebug() << a2->text();


//    MyLineEdit* f2 = reinterpret_cast<MyLineEdit*>(d);
//    f2->fff();





//    ui_->mainTable->setColumnCount(10);
//    ui_->mainTable->setRowCount(10);

//    MyLineEdit* l = new MyLineEdit;
//    l->setText("ddddddd");
//    l->setA(3);

//    ui_->mainTable->setCellWidget(0, 0, l);

//    qDebug() << "======== " << static_cast<MyLineEdit*>(ui_->mainTable->cellWidget(0, 0))->text();
//    static_cast<MyLineEdit*>(ui_->mainTable->cellWidget(0, 0))->fff();












//    QWidget* widget = ui_->mainTable->cellWidget(ui_->mainTable->currentIndex().row(), ui_->mainTable->currentIndex().column());
//    ExtWidget* extWidget = reinterpret_cast<ExtWidget*>(widget);
//    qDebug() << "======== " << extWidget->getFieldAddr()->getName();


//    ProfileCreationWindow clientCreationWindow(
//                namesSetsManager_,
//                defaultFieldsCreator_,
//                defaultFieldDataBase_.getValue(ProfileCategory_Clients),
//                ID_Null,
//                profileDataBaseManager_.getValue(ProfileCategory_Clients),
//                this);
//    clientCreationWindow.exec();

//    mainTableHelper_.refreshClients();
}
