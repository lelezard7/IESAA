#include "IESAAWindow.h"
#include "ui_IESAAWindow.h"


IESAAWindow::
IESAAWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::IESAAWindow)
{
    ui_->setupUi(this);
}

IESAAWindow::
~IESAAWindow()
{
    delete ui_;
}
