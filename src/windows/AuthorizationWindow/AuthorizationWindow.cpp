#include "AuthorizationWindow.h"
#include "ui_AuthorizationWindow.h"

#define EC_NotAccessibleSection 0x00000001


AuthorizationWindow::
AuthorizationWindow(QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::AuthorizationWindow)
    , isShowPass_(false)
{
    ui_->setupUi(this);
    setFixedSize(size());
    messageBar_.setMessageBar(ui_->messageBar);
    messageBar_.resetMessage();

    bg_.addButton(ui_->pushButton_SelectGym);
    bg_.addButton(ui_->pushButton_SelectShop);

    connect(&bg_, QOverload<QAbstractButton*, bool>::of(&QButtonGroup::buttonToggled),
            [&messageBar = messageBar_, &errCode = errCode_](QAbstractButton* button, bool checked) {
        if (button->objectName() == "pushButton_SelectShop") {
            messageBar.setErrorMessage("Раздел \"Магазин\" находится в разработке! Выберите \"Спортзал\".");
            messageBar.freeze(true);

            errCode.setCode(EC_NotAccessibleSection);
            errCode.setDescription("Данная ошибка устанавливается для того что бы пользователь"
                                    "не мог выбрать раздел \"Магазин\", который сейчас находится"
                                    "в разработке!");
        }
        else {
            messageBar.freeze(false);
            messageBar.resetMessage();
            errCode.reset();
        }

        if (checked) {
            button->setIcon(QIcon(":/icons/black/CheckMark"));
        }
        else {
            button->setIcon(QIcon());
        }
    });

    ui_->pushButton_SelectGym->setChecked(true);
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
    messageBar_.resetMessage();
}

void
AuthorizationWindow::
on_lineEdit_Password_textEdited(const QString&)
{
    messageBar_.resetMessage();
}

void
AuthorizationWindow::
on_pushButton_ShowPass_clicked()
{
    if (!isShowPass_) {
        ui_->pushButton_ShowPass->setIcon(QIcon(":/icons/black/ClosedEye"));
        ui_->lineEdit_Password->setEchoMode(QLineEdit::EchoMode::Normal);
        isShowPass_ = true;
        return;
    }

    ui_->pushButton_ShowPass->setIcon(QIcon(":/icons/black/Eye"));
    ui_->lineEdit_Password->setEchoMode(QLineEdit::EchoMode::Password);
    isShowPass_ = false;
}

//Важно! Сперва надо проверять на пустоту строк, а потом на корректность введенных данных,
//иначе можно будет понять что именно введено не верно - логин или пароль.
void
AuthorizationWindow::
on_pushButton_Apply_clicked()
{
    //   === Для демонстрации клиенту ===

    if (errCode_)
        return;

    if (ui_->lineEdit_Login->text() == "") {
        messageBar_.setErrorMessage("Введите логин!");
        return;
    }

    if (ui_->lineEdit_Password->text() == "") {
        messageBar_.setErrorMessage("Введите пароль!");
        return;
    }

    if (ui_->lineEdit_Login->text() != "Artem") {
        messageBar_.setErrorMessage("Не верный логин или пароль!");
        return;
    }

    if (ui_->lineEdit_Password->text() != "321123") {
        messageBar_.setErrorMessage("Не верный логин или пароль!");
        return;
    }

    accept();
}
