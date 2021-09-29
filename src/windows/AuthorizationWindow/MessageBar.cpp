#include "MessageBar.h"
#include "ui_AuthorizationWindow.h"

#include <QMargins>

MessageBar::
MessageBar(Ui::AuthorizationWindow* ui)
    : ui_(ui)
    , isFreeze_ (false) {}

MessageBar::
~MessageBar() {}

bool
MessageBar::
setMessage(std::string_view message)
{
    if (isFreeze_)
        return false;

    QMargins currentMargins = ui_->horizontalLayout_Interface->contentsMargins();
    currentMargins.setBottom(0);
    ui_->horizontalLayout_Interface->setContentsMargins(currentMargins);

    ui_->messageBar->setText(message.data());
    ui_->messageBar->show();
    return true;
}

QString
MessageBar::
getMessage() const
{
    return ui_->messageBar->text();
}

bool
MessageBar::
resetMessage()
{
    if (isFreeze_)
        return false;

    QMargins currentMargins = ui_->horizontalLayout_Interface->contentsMargins();
    currentMargins.setBottom(5);
    ui_->horizontalLayout_Interface->setContentsMargins(currentMargins);

    ui_->messageBar->clear();
    ui_->messageBar->hide();
    return true;
}

void
MessageBar::
freeze(bool value)
{
    isFreeze_ = value;
}

bool
MessageBar::
isFreeze() const
{
    return isFreeze_;
}
