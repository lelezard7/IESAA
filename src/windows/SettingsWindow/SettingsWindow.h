#ifndef SETTINGSWINDOW_H_
#define SETTINGSWINDOW_H_

#include "App.h"
#include "../../LocalDB.h"
#include "FieldsSettingsHelper.h"
#include "DefaultFieldsCreator.h"
#include "../PFCreationWindow/PFCreationWindow.h"
#include "NamesSetsManager.h"

#include <QDialog>








namespace Ui
{
    class SettingsWindow;
}

class SettingsWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::SettingsWindow* ui_;

    NamesSetsManager& namesSetsManager_;
    FieldsSettingsHelper fieldsSettingsHelper_;
    DefaultFieldsCreator* defaultFieldsCreator_;
    DefaultFieldDataBase* defaultFieldDataBase_;

public:
    explicit SettingsWindow(
            NamesSetsManager& namesSetsManager,
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
