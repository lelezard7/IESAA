#ifndef SETTINGSWINDOW_H_
#define SETTINGSWINDOW_H_

#include <QDialog>
#include "../../LocalDB.h"

#include "FieldsSettingsHelper.h"
#include "DefaultFieldsCreator.h"









namespace Ui
{
    class SettingsWindow;
}

class SettingsWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::SettingsWindow* ui_;

    FieldsSettingsHelper fieldsSettingsHelper_;
    DefaultFieldsCreator* defaultFieldsCreator_;
    DefaultFieldDataBase* defaultFieldDataBase_;

public:
    explicit SettingsWindow(
            DefaultFieldsCreator* defaultFieldsCreator,
            DefaultFieldDataBase* defaultFieldDataBase,
            QWidget* parent = nullptr);
    ~SettingsWindow();

private slots:
    void on_pushButton_clicked();
    void on_toolButton_clicked();
    void on_toolButton_2_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

};

#endif
