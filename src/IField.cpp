#include "IField.h"


IField::
IField()
    : id_(0) {}

IField::
~IField() {}

void
IField::
setId(int value)
{
    id_ = value;
}

int
IField::
getId() const
{
    return id_;
}

void
IField::
setName(std::string_view value)
{
    name_ = value.data();
}

QString
IField::
getName()const
{
    return name_;
}

//template<class T>
//void
//IField::
//addData(DataType<T> data)
//{
//    data_.push_back(data);
//}

//std::any
//IField::
//getData(size_t i) const
//{
//    return data_[i];
//}


