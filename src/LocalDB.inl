#include "LocalDB.h"


template<class T>
LocalDataBase<T>::
LocalDataBase() {}

template<class T>
LocalDataBase<T>::
~LocalDataBase()
{
    qsizetype elementsSize = elements_.size();

    for (qsizetype i = 0; i < elementsSize; ++i)
        delete elements_[i];
}

template<class T>
bool
LocalDataBase<T>::
add(T* value)
{
    if (!value)
        return false;

    elements_.push_back(value);
    return true;
}

template<class T>
T*
LocalDataBase<T>::
get(size_t i) const
{
    if (i >= static_cast<size_t>(elements_.size()))
        return nullptr;

    return elements_[i];
}

template<class T>
bool
LocalDataBase<T>::
remove(size_t i)
{
    if (i >= static_cast<size_t>(elements_.size()))
        return false;

    delete elements_[i];
    elements_.erase(i);

    return true;
}

template<class T>
void
LocalDataBase<T>::
clear()
{
    qsizetype elementsSize = elements_.size();

    for (qsizetype i = 0; i < elementsSize; ++i)
        delete elements_[i];

    elements_.clear();
}

template<class T>
qsizetype
LocalDataBase<T>::
size() const
{
    return elements_.size();
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
