#ifndef STAFFWINDOW_H_
#define STAFFWINDOW_H_

#include <QWidget>

namespace Ui
{
    class StaffWindow;
}


class StaffWindow : public QWidget
{
    Q_OBJECT

private:
    Ui::StaffWindow* ui_;

public:
    explicit StaffWindow(QWidget* parent = nullptr);
    ~StaffWindow();

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();

};

#endif
