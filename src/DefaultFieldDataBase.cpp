#include "DefaultFieldDataBase.h"


//DefaultFieldDataBase::
//DefaultFieldDataBase()
//    : AssociativePair<QString, FieldDataBase*>() {}

//DefaultFieldDataBase::
//~DefaultFieldDataBase()
//{
//    qsizetype associativePairsSize = associativePairs_.size();

//    for (qsizetype i = 0; i < associativePairsSize; ++i)
//        delete associativePairs_[i].second;

//    associativePairs_.clear();
//}

//bool
//DefaultFieldDataBase::
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
//DefaultFieldDataBase::
//clear()
//{
//    qsizetype associativePairsSize = associativePairs_.size();

//    for (qsizetype i = 0; i < associativePairsSize; ++i)
//        delete associativePairs_[i].second;

//    associativePairs_.clear();
//}

//bool
//DefaultFieldDataBase::
//isNameCorrect(QString name) const
//{
//    return name != "";
//}

//bool
//DefaultFieldDataBase::
//isValueCorrect(FieldDataBase* value) const
//{
//    return value != nullptr;
//}










//bool
//DefaultFieldDataBase::
//createCategory(QString name)
//{
//    if (name == "")            //TODO: проверять везде.
//        return false;

//    if (find(name))
//        return false;

//    db_.push_back(std::make_pair(std::move(name), new FieldDataBase));
//    return true;
//}

//bool
//DefaultFieldDataBase::
//deleteCategory(QString name)
//{
//    if (name == "")
//        return false;

//    auto it = std::find_if(db_.cbegin(), db_.cend(), [name](const Category& category) {
//              return name == category.first;
//    });

//    if (it == db_.cend())
//        return false;

//    delete it->second;
//    db_.erase(it);
//    return true;
//}

//DefaultFieldManager::Category
//DefaultFieldManager::
//getCategory(size_t i) const
//{
//    if (i >= static_cast<size_t>(db_.size()))
//        return Category();

//    return db_[i];
//}

//FieldDataBase*
//DefaultFieldManager::
//find(QString name) const
//{
//    if (name == "")
//        return nullptr;

//    auto it = std::find_if(db_.cbegin(), db_.cend(), [name](const Category& category) {
//              return name == category.first;
//    });

//    if (it == db_.cend())
//        return nullptr;

//    return it->second;
//}

//size_t
//DefaultFieldManager::
//size() const
//{
//    return db_.size();
//}

//bool
//DefaultFieldManager::
//remove(QString name)
//{
//    if (name == "")
//        return false;

//    auto it = std::find_if(db_.cbegin(), db_.cend(), [name](const Category& category) {
//              return name == category.first;
//    });

//    if (it == db_.cend())
//        return false;

//    delete it->second;
//    db_.erase(it);

//    return true;
//}

//void
//DefaultFieldManager::
//clear()
//{
//    qsizetype dbSize = db_.size();

//    for (qsizetype i = 0; i < dbSize; ++i)
//        delete db_[i].second;

//    db_.clear();
//}
