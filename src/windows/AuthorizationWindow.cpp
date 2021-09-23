#include "AuthorizationWindow.h"
#include "ui_AuthorizationWindow.h"

#include <string_view>


AuthorizationWindow::
AuthorizationWindow(QWidget *parent)
    : QDialog(parent)
    , isShowPass_(false)
    , ui_(new Ui::AuthorizationWindow)
{
    ui_->setupUi(this);
    ui_->label_MessageField->hide();
    resetMessageField();
    setFixedSize(size());
}

AuthorizationWindow::
~AuthorizationWindow()
{
    delete ui_;
}

void
AuthorizationWindow::
on_lineEdit_Login_textEdited(const QString&)
{
    resetMessageField();
}

void
AuthorizationWindow::
on_lineEdit_Password_textEdited(const QString&)
{
    resetMessageField();
}

void
AuthorizationWindow::
on_pushButton_ShowPass_clicked()
{
    if (!isShowPass_) {
        ui_->pushButton_ShowPass->setIcon(QIcon(":/icons/ClosedEye"));
        ui_->lineEdit_Password->setEchoMode(QLineEdit::EchoMode::Normal);
        isShowPass_ = true;
        return;
    }

    ui_->pushButton_ShowPass->setIcon(QIcon(":/icons/Eye"));
    ui_->lineEdit_Password->setEchoMode(QLineEdit::EchoMode::Password);
    isShowPass_ = false;
}

//Важно! Сперва надо проверять на пустоту строк, а потом на корректность введенных данных,
//иначе можно будет понять что именно введено не верно - логин или пароль.
void
AuthorizationWindow::
on_pushButton_Apply_clicked()
{
    if (ui_->lineEdit_Login->text() == "") {
        sendErrMessage("Введите логин!");
        return;
    }

    if (ui_->lineEdit_Password->text() == "") {
        sendErrMessage("Введите пароль!");
        return;
    }

    if (ui_->lineEdit_Login->text() != "Artem") {
        sendErrMessage("Не верный логин или пароль!");
        return;
    }

    if (ui_->lineEdit_Password->text() != "321123") {
        sendErrMessage("Не верный логин или пароль!");
        return;
    }

    accept();
}

void
AuthorizationWindow::
sendErrMessage(std::string_view message)
{
    QMargins currentMargin = ui_->horizontalLayout_5->contentsMargins();
    currentMargin.setBottom(0);
    ui_->horizontalLayout_5->setContentsMargins(currentMargin);

    ui_->label_MessageField->setText(message.data());
    ui_->label_MessageField->show();
}

void
AuthorizationWindow::
resetMessageField()
{
    QMargins currentMargin = ui_->horizontalLayout_5->contentsMargins();
    currentMargin.setBottom(5);
    ui_->horizontalLayout_5->setContentsMargins(currentMargin);

    ui_->label_MessageField->clear();
    ui_->label_MessageField->hide();
}
