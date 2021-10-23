#include "FieldCheckBox.h"


FieldCheckBox::
FieldCheckBox()
    : IFieldWidget()
    , checkBox_   (new QCheckBox) {}

FieldCheckBox::
FieldCheckBox(QCheckBox* checkBox)
    : IFieldWidget()
    , checkBox_   (checkBox) {}

FieldCheckBox::
~FieldCheckBox()
{
    if (checkBox_)
        delete checkBox_;
}

bool
FieldCheckBox::
setWidget(QWidget* widget)
{
    if (!widget)
        return false;

    if (checkBox_)
        delete checkBox_;

    checkBox_ = static_cast<QCheckBox*>(widget);
    return true;
}

QCheckBox*
FieldCheckBox::
getWidget() const
{
    return checkBox_;
}

bool
FieldCheckBox::
isWidgetSet() const
{
    return checkBox_ != nullptr;;
}

FieldCheckBox*
FieldCheckBox::
copy() const
{
    if (!checkBox_)
        return nullptr;

    FieldCheckBox* newFieldCheckBox = new FieldCheckBox;
    newFieldCheckBox->checkBox_ = copyWidget();
    return newFieldCheckBox;
}

QCheckBox*
FieldCheckBox::
copyWidget() const
{
    if (!checkBox_)
        return nullptr;

    QCheckBox* checkBox = getWidget();
    QCheckBox* newCheckBox = new QCheckBox;

    newCheckBox->setChecked(checkBox->isChecked());
    newCheckBox->setStyleSheet(checkBox->styleSheet());
    return newCheckBox;
}

QCheckBox*
FieldCheckBox::
associativeCopyWidget() const
{
    QCheckBox* newCheckBox = copyWidget();
    associateWith(newCheckBox);
    return newCheckBox;
}

bool
FieldCheckBox::
setTextColor(const QColor& color)
{
    return false;
}

QColor
FieldCheckBox::
getTextColor() const
{
    return QColor();
}

bool
FieldCheckBox::
setBkColor(const QColor& color)
{
    return false;
}

QColor
FieldCheckBox::
getBkColor() const
{
    return QColor();
}

void
FieldCheckBox::
reset()
{
    setWidget(new QCheckBox);
}

bool
FieldCheckBox::
associateWith(QWidget* widget) const
{
    QCheckBox* checkBox = static_cast<QCheckBox*>(widget);

    connect(checkBox, &QCheckBox::stateChanged, checkBox_, &QCheckBox::setChecked);
    return true;
}
