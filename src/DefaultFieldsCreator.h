#ifndef DEFAULTFIELDSCREATOR_H_
#define DEFAULTFIELDSCREATOR_H_

#include "AssociativePair.h"
#include "IField.h"

#include <QVector>

#define PairIdNotFound   0x00000000


class DefaultFieldsCreator : public AssociativePair<unsigned, IFieldWidget*>
{
public:
    DefaultFieldsCreator();
    virtual ~DefaultFieldsCreator();

    virtual unsigned getName(size_t i) const override;
    virtual bool isNameCorrect(unsigned name) const override;

    IFieldWidget* copyValue(unsigned name) const;

};

#endif
