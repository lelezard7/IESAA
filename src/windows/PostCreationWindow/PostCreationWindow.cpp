#include "PostCreationWindow.h"
#include "ui_PostCreationWindow.h"


PostCreationWindow::
PostCreationWindow(QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::PostCreationWindow)
{
    ui_->setupUi(this);

    ui_->listWidget->addItem("Создавать, удалять и редактировать должности");
    ui_->listWidget->addItem("Нанимать и увольнять персонал");
    ui_->listWidget->addItem("Оформлять новых клиентов");
}

PostCreationWindow::
~PostCreationWindow()
{
    delete ui_;
}
