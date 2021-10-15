#include "IField.h"





FieldInfo::
FieldInfo()
    : visibility(true) {}

FieldInfo::
~FieldInfo() {}





Field::
Field()
    : widget_(nullptr) {}

Field::
Field(const QString& name, IFieldWidget* widget, FieldInfo fieldInfo)
    : name_     (name)
    , widget_   (widget)
    , fieldInfo_(fieldInfo) {}

Field::
~Field()
{
    if (widget_)
        delete widget_;
}

bool
Field::
setWidget(IFieldWidget* widget)
{
    if (!widget)
        return false;

    if (widget_)
        delete widget_;

    widget_ = widget;
    return true;
}

IFieldWidget*
Field::
getWidget() const
{
    return widget_;
}

void
Field::
setWidgetName(const QString& name)
{
    widgetName_ = name;
}

QString
Field::
getWidgetName() const
{
    return widgetName_;
}

void
Field::
setName(const QString& name)
{
    name_ = name;
}

QString
Field::
getName() const
{
    return name_;
}

Field*
Field::
copy() const
{
    Field* field = new Field;
    field->name_ = name_;
    field->widget_ = widget_->copy();
    field->fieldInfo_ = fieldInfo_;
    return field;
}

void
Field::
setFieldInfo(const FieldInfo& fieldInfo)
{
    fieldInfo_ = fieldInfo;
}

FieldInfo
Field::
getFieldInfo() const
{
    return fieldInfo_;
}

FieldInfo&
Field::
fieldInfo()
{
    return fieldInfo_;
}










