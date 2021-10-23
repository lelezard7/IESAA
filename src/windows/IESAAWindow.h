#ifndef IESAAWINDOW_H_
#define IESAAWINDOW_H_

#include "StaffWindow/StaffWindow.h"
#include "LocalDB.h"
#include "NamesSetsManager.h"
#include "DefaultFieldsCreator.h"
#include "DefaultFieldDataBase.h"
#include "AssociativePair.h"
#include "MainTableHelper.h"
#include "MainTable.h"
#include "Informant.h"
#include "StyleSheetCreator.h"
#include "SubscriptionWindow/SubscriptionWindow.h"
#include "AppStorage.h"

#include <QMainWindow>
#include <QHeaderView>
#include <QMenu>
#include <QScrollArea>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class IESAAWindow;
}
QT_END_NAMESPACE


class TabWidgetManager
{
    QTabWidget* tabWidget_;

    Informant informant_;

public:
    void setTabWidget(QTabWidget* tabWidget);
    QTabWidget* getTabWidget() const;

    Informant* getInformant();

    void showHide();

};



class IESAAWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::IESAAWindow* ui_;
    StaffWindow* staffWindow_;
    QMenu* menu_;

    NamesSetsManager namesSetsManager_;

    DefaultFieldsCreator defaultFieldsCreator_;
    DefaultFieldDataBase defaultFieldDataBase_;
    ProfileDataBaseManager profileDataBaseManager_;

    MainTableHelper mainTableHelper_;
    Informant informant_;

public:
    IESAAWindow(QWidget* parent = nullptr);
    ~IESAAWindow();

private slots:
    void on_action_Settings_triggered();
    void on_action_Log_triggered();
    void on_action_AboutIESAA_triggered();
    void on_action_NewClient_triggered();
    void on_action_NewGroup_triggered();
    void on_action_GroupManagement_triggered();
    void on_action_Staff_triggered();
    void on_action_Statistics_triggered();

    void fff(const QPoint &pos);

    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_pushButton_2_clicked(bool checked);

    void on_action_triggered();
    void on_pushButton_clicked(bool checked);

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_5_clicked();

private:
    void initNamesSets();
    void initDefaultFieldsWidgets();

};






//class IExtention
//{
//    Field* field_;

//public:
//    IExtention() : field_(nullptr) {};
//    virtual ~IExtention() {};

//    void setParentField(Field* field) {
//        field_ = field;
//    };

//    Field* getParentField() {
//        return field_;
//    };

//    virtual QString getWidgetText() = 0;

//};

//class LineEditExtention : public IExtention
//{
//public:
//    QString getWidgetText() override {
//        return dynamic_cast<QLineEdit*>(this)->text();
//    };

//};

//class IExtWidget
//{
//    Field* field_;

//public:
//    void setParentField(Field* field) {
//        field_ = field;
//    };

//    Field* getParentField() {
//        return field_;
//    };

//};

//class MyLineEdit : public QLineEdit, public LineEditExtention
//{

//public:
//    MyLineEdit() : QLineEdit(), LineEditExtention() {};
//    virtual ~MyLineEdit() {};

//};









//class MyIExtention : public QWidget
//{
//    Field* field_;

//public:
//    MyIExtention() : field_(nullptr) {};
//    virtual ~MyIExtention() {};

//    void setParentField(Field* field) {
//        field_ = field;
//    };

//    Field* getParentField() {
//        return field_;
//    };

//    virtual QString getWidgetText() = 0;

//};

//class MyLineEditExtention : public MyIExtention
//{
//public:
//    QString getWidgetText() override {
//        return dynamic_cast<QLineEdit*>(this)->text();
//    };

//};

//class MyLineEdit : virtual public QLineEdit, virtual public MyLineEditExtention
//{

//public:
//    MyLineEdit() : QLineEdit(), MyLineEditExtention() {};
//    virtual ~MyLineEdit() {};

//};





#endif
