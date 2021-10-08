/**
 * PFCreationWindow -  Profile Field Creation Window
 */

#ifndef PFCREATIONWINDOW_H_
#define PFCREATIONWINDOW_H_

#include "FieldCreator.h"
#include "PFCreationHelper.h"
#include "DefaultFieldsCreator.h"
#include "NamesSetsManager.h"
#include "../ProfileCreationWindow/ProfileCreationHelper.h"

#include <QDialog>
#include <QComboBox>

typedef bool (ProfileCreationHelper::*AddField)(Field*);


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

    AddField addField_;
    ProfileCreationHelper* profileCreationHelper_;


public:
    explicit PFCreationWindow(
            NamesSetsManager& namesSetsManager,
            DefaultFieldsCreator& defaultFieldsCreator,
            ProfileCreationHelper* profileCreationHelper,
            AddField addField,
            QWidget* parent = nullptr);
    ~PFCreationWindow();

private slots:
    void on_buttonBox_accepted();

    void on_comboBox_currentTextChanged(const QString &arg1);
};

#endif
