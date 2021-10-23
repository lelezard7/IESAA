#include "FieldDateTimeEdit.h"


FieldDateTimeEdit::
FieldDateTimeEdit()
    : IFieldWidget ()
    , dateTimeEdit_(new QDateTimeEdit) {}

FieldDateTimeEdit::
FieldDateTimeEdit(QDateTimeEdit* dateTimeEdit)
    : IFieldWidget ()
    , dateTimeEdit_(dateTimeEdit) {}

FieldDateTimeEdit::
~FieldDateTimeEdit()
{
    if (dateTimeEdit_)
        delete dateTimeEdit_;
}

bool
FieldDateTimeEdit::
setWidget(QWidget* widget)
{
    if (!widget)
        return false;

    if (dateTimeEdit_)
        delete dateTimeEdit_;

    dateTimeEdit_ = static_cast<QDateTimeEdit*>(widget);
    return true;
}

QDateTimeEdit*
FieldDateTimeEdit::
getWidget() const
{
    return dateTimeEdit_;
}

bool
FieldDateTimeEdit::
isWidgetSet() const
{
    return dateTimeEdit_ != nullptr;
}

FieldDateTimeEdit*
FieldDateTimeEdit::
copy() const
{
    if (!dateTimeEdit_)
        return nullptr;

    FieldDateTimeEdit* newFieldDateTimeEdit = new FieldDateTimeEdit;
    newFieldDateTimeEdit->dateTimeEdit_ = copyWidget();
    return newFieldDateTimeEdit;
}

QDateTimeEdit*
FieldDateTimeEdit::
copyWidget() const
{
    if (!dateTimeEdit_)
        return nullptr;

    QDateTimeEdit* dateTimeEdit = getWidget();
    QDateTimeEdit* newDateTimeEdit = new QDateTimeEdit;

    newDateTimeEdit->setDateTime(dateTimeEdit->dateTime());
    newDateTimeEdit->setCalendarPopup(dateTimeEdit->calendarPopup());
    newDateTimeEdit->setDisplayFormat(dateTimeEdit->displayFormat());
    newDateTimeEdit->setStyleSheet(dateTimeEdit->styleSheet());
    return newDateTimeEdit;
}

QDateTimeEdit*
FieldDateTimeEdit::
associativeCopyWidget() const
{
    QDateTimeEdit* newDateTimeEdit = copyWidget();
    associateWith(newDateTimeEdit);
    return newDateTimeEdit;
}

bool
FieldDateTimeEdit::
setTextColor(const QColor& color)
{
    return false;
}

QColor
FieldDateTimeEdit::
getTextColor() const
{
    return QColor();
}

bool
FieldDateTimeEdit::
setBkColor(const QColor& color)
{
    return false;
}

QColor
FieldDateTimeEdit::
getBkColor() const
{
    return QColor();
}

void
FieldDateTimeEdit::
reset()
{
    setWidget(new QDateTimeEdit);
}

bool
FieldDateTimeEdit::
associateWith(QWidget* widget) const
{
    QDateTimeEdit* dateTimeEdit = static_cast<QDateTimeEdit*>(widget);

    connect(dateTimeEdit, &QDateTimeEdit::dateTimeChanged, dateTimeEdit_, &QDateTimeEdit::setDateTime);
    return true;
}
