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

#include <QMainWindow>
#include <QHeaderView>
#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class IESAAWindow;
}
QT_END_NAMESPACE


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

private:
    void initNamesSets();
    void initDefaultFieldsWidgets();

};

#endif
