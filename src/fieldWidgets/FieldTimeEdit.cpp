#include "FieldTimeEdit.h"


FieldTimeEdit::
FieldTimeEdit()
    : IFieldWidget ()
    , timeEdit_    (new QTimeEdit) {}

FieldTimeEdit::
FieldTimeEdit(QTimeEdit* timeEdit)
    : IFieldWidget ()
    , timeEdit_    (timeEdit) {}

FieldTimeEdit::
~FieldTimeEdit()
{
    if (timeEdit_)
        delete timeEdit_;
}

bool
FieldTimeEdit::
setWidget(QWidget* widget)
{
    if (!widget)
        return false;

    if (timeEdit_)
        delete timeEdit_;

    timeEdit_ = static_cast<QTimeEdit*>(widget);
    return true;
}

QTimeEdit*
FieldTimeEdit::
getWidget() const
{
    return timeEdit_;
}

bool
FieldTimeEdit::
isWidgetSet() const
{
    return timeEdit_ != nullptr;
}

FieldTimeEdit*
FieldTimeEdit::
copy() const
{
    if (!timeEdit_)
        return nullptr;

    FieldTimeEdit* newFieldTimeEdit = new FieldTimeEdit;
    newFieldTimeEdit->timeEdit_ = copyWidget();
    return newFieldTimeEdit;
}

QTimeEdit*
FieldTimeEdit::
copyWidget() const
{
    if (!timeEdit_)
        return nullptr;

    QTimeEdit* timeEdit = getWidget();
    QTimeEdit* newTimeEdit = new QTimeEdit;

    newTimeEdit->setTime(timeEdit->time());
    newTimeEdit->setCalendarPopup(timeEdit->calendarPopup());
    newTimeEdit->setDisplayFormat(timeEdit->displayFormat());
    newTimeEdit->setStyleSheet(timeEdit->styleSheet());
    return newTimeEdit;
}

QTimeEdit*
FieldTimeEdit::
associativeCopyWidget() const
{
    QTimeEdit* newTimeEdit = copyWidget();
    associateWith(newTimeEdit);
    return newTimeEdit;
}

bool
FieldTimeEdit::
setTextColor(const QColor& color)
{
    return false;
}

QColor
FieldTimeEdit::
getTextColor() const
{
    return QColor();
}

bool
FieldTimeEdit::
setBkColor(const QColor& color)
{
    return false;
}

QColor
FieldTimeEdit::
getBkColor() const
{
    return QColor();
}

void
FieldTimeEdit::
reset()
{
    setWidget(new QTimeEdit);
}

bool
FieldTimeEdit::
associateWith(QWidget* widget) const
{
    QTimeEdit* timeEdit = static_cast<QTimeEdit*>(widget);

    connect(timeEdit, &QTimeEdit::timeChanged, timeEdit_, &QTimeEdit::setTime);
    return true;
}
