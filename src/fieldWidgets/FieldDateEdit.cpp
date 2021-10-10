#include "FieldDateEdit.h"


FieldDateEdit::
FieldDateEdit()
    : IFieldWidget()
    , dateEdit_   (new QDateEdit) {}

FieldDateEdit::
FieldDateEdit(QDateEdit* dateEdit)
    : IFieldWidget()
    , dateEdit_   (dateEdit) {}

FieldDateEdit::
~FieldDateEdit()
{
    if (dateEdit_)
        delete dateEdit_;
}

bool
FieldDateEdit::
setWidget(QWidget* widget)
{
    if (!widget)
        return false;

    if (dateEdit_)
        delete dateEdit_;

    dateEdit_ = static_cast<QDateEdit*>(widget);
    return true;
}

QDateEdit*
FieldDateEdit::
getWidget() const
{
    return dateEdit_;
}

bool
FieldDateEdit::
isWidgetSet() const
{
    return dateEdit_ != nullptr;
}

FieldDateEdit*
FieldDateEdit::
copy() const
{
    if (!dateEdit_)
        return nullptr;

    FieldDateEdit* newFieldDateEdit = new FieldDateEdit;
    newFieldDateEdit->dateEdit_ = copyWidget();
    return newFieldDateEdit;
}

QDateEdit*
FieldDateEdit::
copyWidget() const
{
    if (!dateEdit_)
        return nullptr;

    QDateEdit* dateEdit = getWidget();
    QDateEdit* newDateEdit = new QDateEdit;

    newDateEdit->setDate(dateEdit->date());
    newDateEdit->setCalendarPopup(dateEdit->calendarPopup());
    newDateEdit->setDisplayFormat(dateEdit->displayFormat());
    newDateEdit->setStyleSheet(dateEdit->styleSheet());
    return newDateEdit;
}

QDateEdit*
FieldDateEdit::
associativeCopyWidget() const
{
    QDateEdit* newDateEdit = copyWidget();
    associateWith(newDateEdit);
    return newDateEdit;
}

bool
FieldDateEdit::
setTextColor(const QColor& color)
{
    return false;
}

QColor
FieldDateEdit::
getTextColor() const
{
    return QColor();
}

bool
FieldDateEdit::
setBkColor(const QColor& color)
{
    return false;
}

QColor
FieldDateEdit::
getBkColor() const
{
    return QColor();
}

void
FieldDateEdit::
reset()
{
    setWidget(new QDateEdit);
}

bool
FieldDateEdit::
associateWith(QWidget* widget) const
{
    QDateEdit* dateEdit = static_cast<QDateEdit*>(widget);

    connect(dateEdit, &QDateEdit::dateChanged, dateEdit_, &QDateEdit::setDate);
    return true;
}
