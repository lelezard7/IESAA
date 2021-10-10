/**
 * PFCreationWindow -  Profile Field Creation Window
 */

#ifndef PFCREATIONWINDOW_H_
#define PFCREATIONWINDOW_H_

#include "FieldCreator.h"
#include "PFCreationHelper.h"
#include "DefaultFieldsCreator.h"
#include "NamesSetsManager.h"
#include "WindowHelper.h"

#include <QDialog>
#include <QComboBox>




namespace Ui
{
    class PFCreationWindow;
}


class PFCreationWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::PFCreationWindow* ui_;

    PFCreationHelper pf_creationHelper_;

    NamesSetsManager& namesSetsManager_;
    DefaultFieldsCreator& defaultFieldsCreator_;

    FieldReceiver sendField;


public:
    explicit PFCreationWindow(
            NamesSetsManager& namesSetsManager,
            DefaultFieldsCreator& defaultFieldsCreator,
            FieldReceiver fieldReceiver,
            QWidget* parent = nullptr);
    ~PFCreationWindow();

private slots:
    void on_buttonBox_accepted();

    void on_comboBox_currentTextChanged(const QString &arg1);
};

#endif
