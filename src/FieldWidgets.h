#ifndef FIELDWIDGETS_H_
#define FIELDWIDGETS_H_

#include "ExtendedWidgetsManagers/FieldLineEdit.h"
#include "ExtendedWidgetsManagers/FieldTextEdit.h"
#include "ExtendedWidgetsManagers/FieldCheckBox.h"
#include "ExtendedWidgetsManagers/FieldDateEdit.h"
#include "ExtendedWidgetsManagers/FieldDateTimeEdit.h"
#include "ExtendedWidgetsManagers/FieldTimeEdit.h"


bool operator==(const FieldLineEdit& lValue, const FieldLineEdit& rValue);
bool operator!=(const FieldLineEdit& lValue, const FieldLineEdit& rValue);

#endif
