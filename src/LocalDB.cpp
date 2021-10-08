#include "LocalDB.h"


ProfileDataBase::
ProfileDataBase()
    : LocalDataBase<Profile>()
    , idManager_(ID_Start, ID_Step){}

ProfileDataBase::
~ProfileDataBase() {}

bool
ProfileDataBase::
addElement(Profile* profile)
{
    if (!profile)
        return false;

    if (profile->getId() != ID_Null) {
        if (getElementById(profile->getId()))
            return false;

        idManager_.reserve(profile->getId());
        elements_.push_back(profile);
        return true;
    }

    profile->setId(*idManager_.getFreeId());
    elements_.push_back(profile);
    return true;
}

Profile*
ProfileDataBase::
copyElement(size_t i) const
{
    if (i >= static_cast<size_t>(elements_.size()))
        return nullptr;

    return elements_[i]->copy();
}

bool
ProfileDataBase::
remove(size_t i)
{
    if (i >= static_cast<size_t>(elements_.size()))
        return false;

    idManager_.free(elements_[i]->getId());
    delete elements_[i];
    elements_.remove(i);
    return true;
}

void
ProfileDataBase::
clear()
{
    qsizetype elementsSize = elements_.size();

    for (qsizetype i = 0; i < elementsSize; ++i)
        delete elements_[i];

    elements_.clear();
    idManager_.freeAll();
}

Profile*
ProfileDataBase::
getElementById(ID id) const
{
    if (id == ID_Null)
        return nullptr;

    auto it = std::find_if(elements_.begin(), elements_.end(), [id](Profile* const& profile) {
              return id == profile->getId();
    });

    if (it == elements_.end())
        return nullptr;

    return *it;
}

Profile*
ProfileDataBase::
copyElementById(ID id) const
{
    if (id == ID_Null)
        return nullptr;

    auto it = std::find_if(elements_.begin(), elements_.end(), [id](Profile* const& profile) {
              return id == profile->getId();
    });

    if (it == elements_.end())
        return nullptr;

    return (*it)->copy();
}

bool
ProfileDataBase::
removeById(ID id)
{
    if (id == ID_Null)
        return false;

    auto it = std::find_if(elements_.begin(), elements_.end(), [id](Profile* const& profile) {
              return id == profile->getId();
    });

    if (it == elements_.end())
        return false;

    idManager_.free((*it)->getId());
    delete *it;
    elements_.erase(it);
    return true;
}



FieldDataBase::
FieldDataBase()
    : LocalDataBase<Field>() {}

FieldDataBase::
~FieldDataBase() {}

bool
FieldDataBase::
addElement(Field* field)
{
    if (!field)
        return false;

    if (findByName(field->getName()))
        return false;

    elements_.push_back(field);
    return true;
}

Field*
FieldDataBase::
copyElement(size_t i) const
{
    if (i >= static_cast<size_t>(elements_.size()))
        return nullptr;

    return elements_[i]->copy();
}

Field*
FieldDataBase::
copyElementByName(const QString& name) const
{
    if (name == "")
        return nullptr;

    auto it = std::find_if(elements_.cbegin(), elements_.cend(), [name](Field* const& field) {
              return name == field->getName();
    });

    if (it == elements_.cend())
        return nullptr;

    return (*it)->copy();
}

bool
FieldDataBase::
removeByName(const QString& name)
{
    if (name == "")
        return "";

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
findByName(const QString& name) const
{
    if (name == "")
        return nullptr;

    auto it = std::find_if(elements_.cbegin(), elements_.cend(), [name](Field* const& field) {
              return name == field->getName();
    });

    if (it == elements_.cend())
        return nullptr;

    return *it;
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
