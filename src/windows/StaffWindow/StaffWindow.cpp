#include "StaffWindow.h"
#include "ui_StaffWindow.h"

#include "../PostCreationWindow/PostCreationWindow.h"
#include "../ProfileCreationWindow/ProfileCreationWindow.h"
#include "../EmployeeDefinitionWindow/EmployeeDefinitionWindow.h"


StaffWindow::
StaffWindow(QWidget* parent)
    : QWidget(parent)
    , ui_(new Ui::StaffWindow)
{
    ui_->setupUi(this);
}

StaffWindow::
~StaffWindow()
{
    delete ui_;
}

void
StaffWindow::
on_pushButton_4_clicked()
{
    PostCreationWindow postCreationWindow(this);
    postCreationWindow.exec();
}

void
StaffWindow::
on_pushButton_clicked()
{
    ProfileCreationWindow clientCreationWindow(this);
    clientCreationWindow.exec();

    EmployeeDefinitionWindow employeeDefinitionWindow(this);
    employeeDefinitionWindow.exec();
}
