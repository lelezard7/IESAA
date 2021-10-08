#ifndef DEFAULTFIELDSCREATOR_H_
#define DEFAULTFIELDSCREATOR_H_

#include "AssociativePair.h"
#include "IField.h"

#include <QVector>


class DefaultFieldsCreator : public AssociativePair<QString, IFieldWidget*>
{
public:
    DefaultFieldsCreator();
    virtual ~DefaultFieldsCreator();

    IFieldWidget* copyValue(const QString& name) const;

};

#endif
