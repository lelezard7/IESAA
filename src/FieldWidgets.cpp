#include "FieldWidgets.h"


bool
operator==(const FieldLineEdit& lValue, const FieldLineEdit& rValue)
{
    if (!lValue.isWidgetSet() || !rValue.isWidgetSet())
        return false;

    QLineEdit* lLineEdit = lValue.getWidget();
    QLineEdit* rLineEdit = rValue.getWidget();

    return lLineEdit->text() == rLineEdit->text();
}

bool
operator!=(const FieldLineEdit& lValue, const FieldLineEdit& rValue)
{
    if (!lValue.isWidgetSet() || !rValue.isWidgetSet())
        return false;

    QLineEdit* lLineEdit = lValue.getWidget();
    QLineEdit* rLineEdit = rValue.getWidget();

    return lLineEdit->text() != rLineEdit->text();
}
