#ifndef FIELDWIDGETS_H_
#define FIELDWIDGETS_H_

#include "FieldWidgets/FieldLineEdit.h"
#include "FieldWidgets/FieldTextEdit.h"
#include "FieldWidgets/FieldCheckBox.h"
#include "FieldWidgets/FieldDateEdit.h"
#include "FieldWidgets/FieldDateTimeEdit.h"
#include "FieldWidgets/FieldTimeEdit.h"


bool operator==(const FieldLineEdit& lValue, const FieldLineEdit& rValue);
bool operator!=(const FieldLineEdit& lValue, const FieldLineEdit& rValue);

#endif
