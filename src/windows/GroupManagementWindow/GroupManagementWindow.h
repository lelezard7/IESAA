#ifndef GROUPMANAGEMENTWINDOW_H_
#define GROUPMANAGEMENTWINDOW_H_

#include <QDialog>

namespace Ui
{
    class GroupManagementWindow;
}


class GroupManagementWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::GroupManagementWindow* ui_;

public:
    explicit GroupManagementWindow(QWidget* parent = nullptr);
    ~GroupManagementWindow();

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();

};

#endif
