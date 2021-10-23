#include "DefaultFieldsCreator.h"


DefaultFieldsCreator::
DefaultFieldsCreator()
    : AssociativePair<unsigned, IFieldWidget*>() {}

DefaultFieldsCreator::
~DefaultFieldsCreator() {}

unsigned
DefaultFieldsCreator::
getName(size_t i) const
{
    if (i >= static_cast<size_t>(associativePairs_.size()))
        return PairIdNotFound;

    return associativePairs_[i].first;
}

bool
DefaultFieldsCreator::
isNameCorrect(unsigned name) const
{
    return name != PairIdNotFound;
}

IFieldWidget*
DefaultFieldsCreator::
copyValue(unsigned name) const
{
    if (!isNameCorrect(name))
        return nullptr;

    auto it = getAssociativePairsIt(name);

    if (it == associativePairs_.cend())
        return nullptr;

    return it->second->copy();
}
