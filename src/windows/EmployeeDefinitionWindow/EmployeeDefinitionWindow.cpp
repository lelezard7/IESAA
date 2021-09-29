#include "EmployeeDefinitionWindow.h"
#include "ui_EmployeeDefinitionWindow.h"


EmployeeDefinitionWindow::
EmployeeDefinitionWindow(QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::EmployeeDefinitionWindow)
{
    ui_->setupUi(this);

    setFixedSize(size());
}

EmployeeDefinitionWindow::
~EmployeeDefinitionWindow()
{
    delete ui_;
}
