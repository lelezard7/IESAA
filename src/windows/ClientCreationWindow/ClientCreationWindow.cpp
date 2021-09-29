#include "ClientCreationWindow.h"
#include "ui_ClientCreationWindow.h"

#include "../CPFCreationWindow/CPFCreationWindow.h"


ClientCreationWindow::
ClientCreationWindow(QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::ClientCreationWindow)
{
    ui_->setupUi(this);
}

ClientCreationWindow::
~ClientCreationWindow()
{
    delete ui_;
}

void
ClientCreationWindow::
on_pushButton_clicked()
{
    CPFCreationWindow cpf_creationWindow;
    cpf_creationWindow.exec();
}

void
ClientCreationWindow::
on_pushButton_2_clicked()
{
    CPFCreationWindow cpf_creationWindow;
    cpf_creationWindow.exec();
}
