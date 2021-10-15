#include "MessageBar.h"


MessageBar::
MessageBar(QLabel* messageBar)
    : messageBar_(messageBar)
    , isFreeze_ (false) {}

MessageBar::
~MessageBar() {}

void
MessageBar::
setMessageBar(QLabel* messageBar)
{ messageBar_ = messageBar; }

QLabel*
MessageBar::
getMessageBar() const
{ return messageBar_; }

bool
MessageBar::
setInfoMessage(const QString& message)
{
    StyleSheetCreator styleSheetCreator;
    styleSheetCreator.setProperty("QLabel", "background-color", "#9966cc");
    styleSheetCreator.setProperty("QLabel", "color", "#f5f5f5");
    styleSheetCreator.setProperty("QLabel", "padding", "2px");

    return setMessage(message, &styleSheetCreator);
}

bool
MessageBar::
setWarningMessage(const QString& message)
{
    StyleSheetCreator styleSheetCreator;
    styleSheetCreator.setProperty("QLabel", "background-color", "#ffc618");
    styleSheetCreator.setProperty("QLabel", "color", "black");
    styleSheetCreator.setProperty("QLabel", "padding", "2px");

    return setMessage(message, &styleSheetCreator);
}

bool
MessageBar::
setErrorMessage(const QString& message)
{
    StyleSheetCreator styleSheetCreator;
    styleSheetCreator.setProperty("QLabel", "background-color", "#e32636");
    styleSheetCreator.setProperty("QLabel", "color", "#f5f5f5");
    styleSheetCreator.setProperty("QLabel", "padding", "2px");

    return setMessage(message, &styleSheetCreator);
}

QString
MessageBar::
getMessage() const
{ return messageBar_->text(); }

bool
MessageBar::
resetMessage(const QString& message)
{
    if (isFreeze_)
        return false;

    if (message != messageBar_->text())
        return false;

    messageBar_->clear();
    messageBar_->hide();
    return true;
}

bool
MessageBar::
resetMessage()
{
    if (isFreeze_)
        return false;

    messageBar_->clear();
    messageBar_->hide();
    return true;
}

void
MessageBar::
reset()
{
    messageBar_->clear();
    messageBar_->hide();
    isFreeze_ = false;
}

void
MessageBar::
freeze(bool value)
{ isFreeze_ = value; }

bool
MessageBar::
isFreeze() const
{ return isFreeze_; }

bool
MessageBar::
setMessage(const QString& message, StyleSheetCreator* styleSheetCreator)
{
    if (isFreeze_)
        return false;

    if (styleSheetCreator)
        messageBar_->setStyleSheet(styleSheetCreator->getStyleSheet());

    messageBar_->setText(message);
    messageBar_->show();
    return true;
}
