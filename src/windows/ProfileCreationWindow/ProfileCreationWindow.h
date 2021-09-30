#ifndef PROFILECREATIONWINDOW_H_
#define PROFILECREATIONWINDOW_H_

#include <QDialog>

namespace Ui
{
    class ProfileCreationWindow;
}


class ProfileCreationWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::ProfileCreationWindow* ui_;

public:
    explicit ProfileCreationWindow(QWidget* parent = nullptr);
    ~ProfileCreationWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

};

#endif
