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
Field(std::string_view name, IFieldWidget* widget, FieldInfo fieldInfo)
    : name_     (name.data())
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
setName(std::string_view name)
{
    name_ = name.data();
}

QString
Field::
getName() const
{
    return name_;
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










