#include "LocalDB.h"


ProfileDataBase::
ProfileDataBase()
    : LocalDataBase<Profile>() {}

ProfileDataBase::
~ProfileDataBase() {}

bool
ProfileDataBase::
add(Profile* profile)
{
    if (!profile)
        return false;

    if (findById(profile->getId()))
        return false;

    elements_.push_back(profile);
    return true;
}

bool
ProfileDataBase::
removeById(ID id)
{
    auto it = std::find_if(elements_.cbegin(), elements_.cend(), [id](Profile* const& profile) {
              return id == profile->getId();
    });

    if (it == elements_.cend())
        return false;

    delete *it;
    elements_.erase(it);

    return true;
}

Profile*
ProfileDataBase::
findById(ID id) const
{
    auto it = std::find_if(elements_.begin(), elements_.end(), [id](Profile* const& profile) {
              return id == profile->getId();
    });

    if (it == elements_.end())
        return nullptr;

    return *it;
}



FieldDataBase::
FieldDataBase()
    : LocalDataBase<Field>() {}

FieldDataBase::
~FieldDataBase() {}

bool
FieldDataBase::
add(Field* field)
{
    if (!field)
        return false;

    if (findByName(field->getName()))
        return false;

    elements_.push_back(field);
    return true;
}

bool
FieldDataBase::
removeByName(QString name)
{
    auto it = std::find_if(elements_.cbegin(), elements_.cend(), [name](Field* const& field) {
              return name == field->getName();
    });

    if (it == elements_.cend())
        return false;

    delete *it;
    elements_.erase(it);

    return true;
}

Field*
FieldDataBase::
findByName(QString name) const
{
    auto it = std::find_if(elements_.cbegin(), elements_.cend(), [name](Field* const& field) {
              return name == field->getName();
    });

    if (it == elements_.cend())
        return nullptr;

    return *it;
}











DefaultFieldManager::
DefaultFieldManager() {}

DefaultFieldManager::
~DefaultFieldManager()
{
    qsizetype dbSize = db_.size();

    for (qsizetype i = 0; i < dbSize; ++i)
        delete db_[i].second;
}

bool
DefaultFieldManager::
createCategory(QString name)
{
    if (name == "")            //TODO: проверять везде.
        return false;

    if (find(name))
        return false;

    db_.push_back(std::make_pair(std::move(name), new FieldDataBase));
    return true;
}

bool
DefaultFieldManager::
deleteCategory(QString name)
{
    if (name == "")
        return false;

    auto it = std::find_if(db_.cbegin(), db_.cend(), [name](const Category& category) {
              return name == category.first;
    });

    if (it == db_.cend())
        return false;

    delete it->second;
    db_.erase(it);
    return true;
}

DefaultFieldManager::Category
DefaultFieldManager::
getCategory(size_t i) const
{
    if (i >= static_cast<size_t>(db_.size()))
        return Category();

    return db_[i];
}

FieldDataBase*
DefaultFieldManager::
find(QString name) const
{
    if (name == "")
        return nullptr;

    auto it = std::find_if(db_.cbegin(), db_.cend(), [name](const Category& category) {
              return name == category.first;
    });

    if (it == db_.cend())
        return nullptr;

    return it->second;
}

size_t
DefaultFieldManager::
size() const
{
    return db_.size();
}

bool
DefaultFieldManager::
remove(QString name)
{
    if (name == "")
        return false;

    auto it = std::find_if(db_.cbegin(), db_.cend(), [name](const Category& category) {
              return name == category.first;
    });

    if (it == db_.cend())
        return false;

    delete it->second;
    db_.erase(it);

    return true;
}

void
DefaultFieldManager::
clear()
{
    qsizetype dbSize = db_.size();

    for (qsizetype i = 0; i < dbSize; ++i)
        delete db_[i].second;

    db_.clear();
}















//DefConvertTo(int, QSpinBox)



//template <class T>
//LocalDB<T>::
//LocalDB() {}

//template <class T>
//LocalDB<T>::
//~LocalDB() {}

//template<class T>
//size_t
//LocalDB<T>::
//size() const
//{
//    return elements_.size();
//}


//bool
//ProfilesDB::
//add(IProfile* profile)
//{
//    QVector<IProfile*>::const_iterator dd = std::find_if(elements_.cbegin(), elements_.cend(),
//                     [profile](const IProfile* it) {
//        return profile->getName() == it->getName();
//    });

//    if (dd != elements_.cend())
//        return false;

//    elements_.push_back(profile);
//    return true;
//}

//IProfile*
//ProfilesDB::
//get(QString name) const
//{
//    QVector<IProfile*>::const_iterator dd = std::find_if(elements_.cbegin(), elements_.cend(),
//                     [&name](const IProfile* it) {
//        return name == it->getName();
//    });

//    if (dd == elements_.cend())
//        return nullptr;

//    return *dd;
//}


//FieldsDB::
//FieldsDB()
//{
//    fieldsContainer_ = std::make_unique<IProfile>();
//}

//FieldsDB::
//~FieldsDB() {}

//template<class T_Data, class T_Ui>
//bool
//FieldsDB::
//add(IField<T_Data, T_Ui>* field)
//{

//}

//template<class T_Data, class T_Ui>
//IField<T_Data, T_Ui>*
//FieldsDB::
//get(QString name) const
//{
//    size_t i = 0;

//    while (true) {
//        switch (fieldsContainer_->getFieldTypeId(i)) {
//            case DATATYPE_ID(int, QSpinBox): {
//                auto data = CastToint_QSpinBox(*fieldsContainer_.get());
//                if (name == data.getName())
//                    return data.getName();
//            }
//        }

//        ++i;
//    }


//}











//static ProfilesDB staffDB;
//static FieldsDB defaultFieldsDB;



//bool
//addStaff(IProfile* profile)
//{
//    return staffDB.add(profile);
//}

//IProfile*
//getStaff(QString name)
//{
//    return staffDB.get(std::move(name));
//}


//template <class T_Data, class T_Ui>
//bool
//addDefaultField(IField<T_Data, T_Ui>* field)
//{
//    return defaultFieldsDB.add(field);
//}

//template <class T_Data, class T_Ui>
//IField<T_Data, T_Ui>*
//getDefaultField(QString name)
//{
//    return defaultFieldsDB.get<T_Data, T_Ui>(std::move(name));
//}
