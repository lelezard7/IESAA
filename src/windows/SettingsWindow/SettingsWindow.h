#ifndef SETTINGSWINDOW_H_
#define SETTINGSWINDOW_H_

#include <QDialog>
#include "../../LocalDB.h"









namespace Ui
{
    class SettingsWindow;
}

class SettingsWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::SettingsWindow* ui_;

public:
    explicit SettingsWindow(QWidget* parent = nullptr);
    ~SettingsWindow();

private slots:
    void on_pushButton_clicked();
    void on_toolButton_clicked();
    void on_toolButton_2_clicked();

};

#endif
