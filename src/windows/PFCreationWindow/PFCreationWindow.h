/**
 * PFCreationWindow -  Profile Field Creation Window
 */

#ifndef PFCREATIONWINDOW_H_
#define PFCREATIONWINDOW_H_

#include <QDialog>

#include "../../LocalDB.h"
#include "FieldCreator.h"


namespace Ui
{
    class PFCreationWindow;
}


class PFCreationWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::PFCreationWindow* ui_;
    IProfile* profile_;
    FieldCreator fieldCreator;

public:
    explicit PFCreationWindow(IProfile* profile, QWidget* parent = nullptr);
    ~PFCreationWindow();

private slots:
    void on_buttonBox_accepted();

};

#endif
