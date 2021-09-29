#ifndef EMPLOYEEDEFINITIONWINDOW_H_
#define EMPLOYEEDEFINITIONWINDOW_H_

#include <QDialog>

namespace Ui
{
    class EmployeeDefinitionWindow;
}


class EmployeeDefinitionWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::EmployeeDefinitionWindow* ui_;

public:
    explicit EmployeeDefinitionWindow(QWidget* parent = nullptr);
    ~EmployeeDefinitionWindow();

};

#endif
