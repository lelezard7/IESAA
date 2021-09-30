#ifndef IFIELD_H_
#define IFIELD_H_

#include "IESAA.h"

#include <QString>
#include <string_view>
#include <any>
#include <initializer_list>


template<class T>
class DataType
{
    std::vector<T> data_;

public:
    DataType() {};
    DataType(std::initializer_list<T> value) { data_.push_back(*value.begin()); };
    virtual ~DataType() {};

    void addData(T data) {
        data_.push_back(data);
    };

    T getData(size_t i) const {
        return data_[i];
    };

};


class IField
{
    ID id_;
    QString name_;

    std::vector<std::any> data_;

public:
    IField();
    virtual ~IField();

    void setId(int value);
    int getId() const;

    void setName(std::string_view value);
    QString getName() const;

    template<class T>
    void addData(DataType<T> data) {
        data_.push_back(data);
    };

    template<class T>
    DataType<T> getData(size_t i) const {
        return std::any_cast<DataType<T>>(data_[i]);
    };

};

#endif
