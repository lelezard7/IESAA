#include "IProfile.h"






Profile::
Profile()
    : id_(ID_Null) {}

Profile::
~Profile()
{
    qsizetype fieldsSize = fields_.size();

    for (qsizetype i = 0; i < fieldsSize; ++i)
        delete fields_[i];

    fields_.clear();
}

void
Profile::
setId(ID id)
{
    id_ = id;
}

ID
Profile::
getId() const
{
    return id_;
}

bool
Profile::
addField(Field* field)
{
    if (getField(field->getName()))
        return false;

    fields_.push_back(field);
    return true;
}

Field*
Profile::
getField(const QString& name) const
{
    auto it = std::find_if(fields_.begin(), fields_.end(), [name](Field* const& field) {
              return name == field->getName();
    });

    if (it == fields_.end())
        return nullptr;

    return *it;
}

Field*
Profile::
getField(size_t i) const
{
    if (i >= static_cast<size_t>(fields_.size()))
        return nullptr;

    return fields_[i];
}

QString
Profile::
getFieldName(size_t i) const
{
    if (i >= static_cast<size_t>(fields_.size()))
        return "";

    return fields_[i]->getName();
}

size_t
Profile::
fieldsCount() const
{
    return fields_.size();
}

Profile*
Profile::
copy() const
{
    Profile* newProfile = new Profile;
    newProfile->id_ = id_;

    qsizetype fieldsSize = fields_.size();

    for (qsizetype i = 0; i < fieldsSize; ++i)
        newProfile->addField(fields_[i]->copy());

    return newProfile;
}

Field*
Profile::
copyField(const QString& name) const
{
    if (name == "")
        return nullptr;

    auto it = std::find_if(fields_.begin(), fields_.end(), [name](Field* const& field) {
              return name == field->getName();
    });

    if (it == fields_.end())
        return nullptr;

    return (*it)->copy();
}

void
Profile::
clear()
{
    qsizetype fieldsSize = fields_.size();

    for (qsizetype i = 0; i < fieldsSize; ++i)
        delete fields_[i];

    fields_.clear();
}

bool
Profile::
swap(size_t value1, size_t value2)
{
    if (value1 == value2)
        return true;

    if (value1 >= static_cast<size_t>(fields_.size()))
        return false;

    if (value2 >= static_cast<size_t>(fields_.size()))
        return false;

    std::swap(fields_[value1], fields_[value2]);
    return true;
}

bool
Profile::
move(size_t value, size_t target)
{
    if (value == target)
        return true;

    if (value >= static_cast<size_t>(fields_.size()))
        return false;

    if (target >= static_cast<size_t>(fields_.size())) //TODO: target ???????????????? ?????????? ???????? == size
        return false;

    auto itBegin = fields_.begin();

    std::rotate(itBegin + value, itBegin + value + 1, itBegin + target);   //TODO: ?????????????? ??????. ????????????????.
    return true;
}































//IProfile::
//IProfile()
//    : id_(0)
//{

//}

//IProfile::
//~IProfile()
//{

//}

//bool
//IProfile::
//addField(IField* field)
//{
//    fields_.push_back(field);

//    return true;
//}

//const IField&
//IProfile::
//getField(int i)
//{
//    return *fields_[i];
//}

//bool
//IProfile::
//removeField(int i)
//{
//    fields_.remove(i);
//    return true;
//}

//void
//IProfile::
//setId(int value)
//{
//    id_ = value;
//}

//int
//IProfile::
//getId()
//{
//    return id_;
//}

//void
//IProfile::
//setName(QString value)
//{
//    name_ = value;
//}

//QString
//IProfile::
//getName()
//{
//    return name_;
//}


//HumanProfile::
//HumanProfile()
//    : IProfile()
//{

//}

//HumanProfile::
//~HumanProfile()
//{

//}


//ClientProfile::
//ClientProfile()
//    : HumanProfile()
//{

//}

//ClientProfile::
//~ClientProfile()
//{

//}


