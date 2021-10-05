#ifndef IESAAWINDOW_H_
#define IESAAWINDOW_H_

#include "StaffWindow/StaffWindow.h"
#include "LocalDB.h"

#include <QMainWindow>
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

    DefaultFieldManager defaultFieldManager;

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
};

#endif
