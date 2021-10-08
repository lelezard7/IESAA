#include "DefaultFieldsCreator.h"


DefaultFieldsCreator::
DefaultFieldsCreator()
    : AssociativePair<QString, IFieldWidget*>() {}

DefaultFieldsCreator::
~DefaultFieldsCreator()
{
//    qsizetype associativePairsSize = associativePairs_.size();

//    for (qsizetype i = 0; i < associativePairsSize; ++i)
//        delete associativePairs_[i].second;

//    associativePairs_.clear();
}

//bool
//DefaultFieldsCreator::
//deleteAssociation(QString name)
//{
//    if (!isNameCorrect(name))
//        return false;

//    auto it = getAssociativePairsIt(name);

//    if (it == associativePairs_.end())
//        return false;

//    delete it->second;
//    associativePairs_.erase(it);
//    return true;
//}

//void
//DefaultFieldsCreator::
//clear()
//{
//    qsizetype associativePairsSize = associativePairs_.size();

//    for (qsizetype i = 0; i < associativePairsSize; ++i)
//        delete associativePairs_[i].second;

//    associativePairs_.clear();
//}

IFieldWidget*
DefaultFieldsCreator::
copyValue(const QString& name) const
{
    if (!isNameCorrect(name))
        return nullptr;

    auto it = getAssociativePairsIt(name);

    if (it == associativePairs_.cend())
        return nullptr;

    return it->second->copy();
}

//bool
//DefaultFieldsCreator::
//isNameCorrect(QString name) const
//{
//    return name != "";
//}

//bool
//DefaultFieldsCreator::
//isValueCorrect(IFieldWidget* value) const
//{
//    return value != nullptr;
//}
















//bool
//DefaultFieldsCreator::
//createAssociation(const QString& name, IFieldWidget* fieldWidget)
//{
//    if (name == "" || !fieldWidget)
//        return false;

//    if (getDefaultFieldsIt(name) != defaultFields_.end())
//        return false;

//    defaultFields_.push_back(std::make_pair(name, fieldWidget));
//    return true;
//}

//bool
//DefaultFieldsCreator::
//deleteAssociation(const QString& name)
//{
//    if (name == "")
//        return false;

//    auto it = getDefaultFieldsIt(name);

//    if (it == defaultFields_.end())
//        return false;

//    delete it->second;
//    defaultFields_.erase(it);
//    return true;
//}

//IFieldWidget*
//DefaultFieldsCreator::
//copyFieldWidget(const QString& name) const
//{
//    if (name == "")
//        return nullptr;

//    auto it = getDefaultFieldsIt(name);

//    if (it == defaultFields_.cend())
//        return nullptr;

//    return it->second->copy();
//}

//IFieldWidget*
//DefaultFieldsCreator::
//getFieldWidget(const QString& name) const
//{
//    if (name == "")
//        return nullptr;

//    auto it = getDefaultFieldsIt(name);

//    if (it == defaultFields_.cend())
//        return nullptr;

//    return it->second;
//}

//QString
//DefaultFieldsCreator::
//getName(size_t i) const
//{
//    if (i >= static_cast<size_t>(defaultFields_.size()))
//        return "";

//    return defaultFields_[i].first;
//}

//bool
//DefaultFieldsCreator::
//find(const QString& name) const
//{
//    if (name == "")
//        return false;

//    return getDefaultFieldsIt(name) != defaultFields_.cend();
//}

//size_t
//DefaultFieldsCreator::
//size() const
//{
//    return defaultFields_.size();
//}

//QVector<DefaultFieldsCreator::DefaultField>::Iterator
//DefaultFieldsCreator::
//getDefaultFieldsIt(const QString& name)
//{
//    if (name == "")
//        return defaultFields_.end();

//    return std::find_if(defaultFields_.begin(), defaultFields_.end(), [name](const DefaultField& defaultField) {
//        return name == defaultField.first;
//    });
//}

//QVector<DefaultFieldsCreator::DefaultField>::ConstIterator
//DefaultFieldsCreator::
//getDefaultFieldsIt(const QString& name) const
//{
//    if (name == "")
//        return defaultFields_.cend();

//    return std::find_if(defaultFields_.cbegin(), defaultFields_.cend(), [name](const DefaultField& defaultField) {
//        return name == defaultField.first;
//    });
//}
