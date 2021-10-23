#include "WidgetExtension.h"
#include "StyleSheetCreator.h"


IWidgetExtension::
IWidgetExtension()
    : parentField_(nullptr) {}

IWidgetExtension::
~IWidgetExtension() {}

void
IWidgetExtension::
setParentField(Field* parentField)
{ parentField_ = parentField; }

Field*
IWidgetExtension::
getParentField() const
{ return parentField_; }









LineEditExtension::
LineEditExtension()
    : IWidgetExtension() {}

LineEditExtension::
~LineEditExtension() {}

void
LineEditExtension::
resetWidget()
{
    QLineEdit* thisLineEdit = dynamic_cast<QLineEdit*>(this);
    thisLineEdit->clear();
    thisLineEdit->setStyleSheet("QLineEdit {}");
}

void
LineEditExtension::
clearData()
{
    QLineEdit* thisLineEdit = dynamic_cast<QLineEdit*>(this);
    thisLineEdit->clear();
}

bool
LineEditExtension::
setContentColor(const QColor& color)
{
//    StyleSheetCreator styleSheetCreator;
//    styleSheetCreator.setProperty("QLineEdit", "color", color.name(QColor::HexArgb));

//    QLineEdit* thisLineEdit = dynamic_cast<QLineEdit*>(this);
//    thisLineEdit.
    return true;
}

QColor
LineEditExtension::
getContentColor() const
{
    return QColor();
}

bool
LineEditExtension::
setBgColor(const QColor& color)
{
    return true;
}

QColor
LineEditExtension::
getBgColor() const
{
    return QColor();
}
