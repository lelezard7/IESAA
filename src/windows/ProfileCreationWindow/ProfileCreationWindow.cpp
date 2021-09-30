#include "ProfileCreationWindow.h"
#include "ui_ProfileCreationWindow.h"

#include "../PFCreationWindow/PFCreationWindow.h"


ProfileCreationWindow::
ProfileCreationWindow(QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::ProfileCreationWindow)
{
    ui_->setupUi(this);
}

ProfileCreationWindow::
~ProfileCreationWindow()
{
    delete ui_;
}

void
ProfileCreationWindow::
on_pushButton_clicked()
{
    PFCreationWindow cpf_creationWindow;
    cpf_creationWindow.exec();
}

void
ProfileCreationWindow::
on_pushButton_2_clicked()
{
    PFCreationWindow cpf_creationWindow;
    cpf_creationWindow.exec();
}
