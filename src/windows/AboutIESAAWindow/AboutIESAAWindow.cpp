#include "AboutIESAAWindow.h"
#include "ui_AboutIESAAWindow.h"


AboutIESAAWindow::
AboutIESAAWindow(QWidget *parent)
    : QDialog(parent)
    , ui_(new Ui::AboutIESAAWindow)
{
    ui_->setupUi(this);
    setFixedSize(size());
}

AboutIESAAWindow::
~AboutIESAAWindow()
{
    delete ui_;
}
