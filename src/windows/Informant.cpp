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
    if (value) {

        isViewed_ = value;
        return;
    }

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
    setViewed(true);
}

bool
Informant::
sendWarningMessage(const QString& message)
{
    setViewed(true);
}

bool
Informant::
sendErrorMessage(const QString& message)
{
    setViewed(true);
}

void
Informant::
setButtonColor(const QColor& color)
{
//    pushButton_->setStyleSheet()
}
