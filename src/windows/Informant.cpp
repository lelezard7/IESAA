#include "Informant.h"


Informant::
Informant()
    : isViewed_  (true)
    , pushButton_(nullptr) {}

Informant::
Informant(QPushButton* pushButton)
    : isViewed_  (true)
    , pushButton_(pushButton) {}

Informant::
~Informant() {}

void
Informant::
setPushButton(QPushButton* pushButton)
{
    pushButton_ = pushButton;
}

QPushButton*
Informant::
getPushButton() const
{
    return pushButton_;
}

void
Informant::
setViewed(bool value)
{
    StyleSheetCreator styleSheetCreator;

    if (value) {
        styleSheetCreator.setProperty("QPushButton", "background-color", "blue");
        pushButton_->setStyleSheet(styleSheetCreator.getStyleSheet());
        isViewed_ = value;
        return;
    }

    styleSheetCreator.setProperty("QPushButton", "background-color", "red");
    pushButton_->setStyleSheet(styleSheetCreator.getStyleSheet());
    isViewed_ = value;
}

bool
Informant::
isViewed() const
{
    return isViewed_;
}

bool
Informant::
sendInfoMessage(const QString& message)
{
    setViewed(false);
}

bool
Informant::
sendWarningMessage(const QString& message)
{
    setViewed(false);
}

bool
Informant::
sendErrorMessage(const QString& message)
{
    setViewed(false);
}

void
Informant::
setButtonColor(const QColor& color)
{
//    pushButton_->setStyleSheet()
}
