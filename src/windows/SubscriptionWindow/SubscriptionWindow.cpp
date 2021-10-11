#include "SubscriptionWindow.h"
#include "ui_SubscriptionWindow.h"


SubscriptionWindow::
SubscriptionWindow(QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::SubscriptionWindow)
{
    ui_->setupUi(this);
}

SubscriptionWindow::
~SubscriptionWindow()
{
    delete ui_;
}
