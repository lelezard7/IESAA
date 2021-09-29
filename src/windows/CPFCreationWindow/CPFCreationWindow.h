/**
 * CPFCreationWindow - Client Profile Field Creation Window
 */

#ifndef CPFCREATIONWINDOW_H_
#define CPFCREATIONWINDOW_H_

#include <QDialog>

namespace Ui
{
    class CPFCreationWindow;
}


class CPFCreationWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::CPFCreationWindow* ui_;

public:
    explicit CPFCreationWindow(QWidget *parent = nullptr);
    ~CPFCreationWindow();

};

#endif
