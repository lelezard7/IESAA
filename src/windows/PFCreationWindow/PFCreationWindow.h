/**
 * PFCreationWindow -  Profile Field Creation Window
 */

#ifndef PFCREATIONWINDOW_H_
#define PFCREATIONWINDOW_H_

#include <QDialog>

namespace Ui
{
    class PFCreationWindow;
}


class PFCreationWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::PFCreationWindow* ui_;

public:
    explicit PFCreationWindow(QWidget* parent = nullptr);
    ~PFCreationWindow();

};

#endif
