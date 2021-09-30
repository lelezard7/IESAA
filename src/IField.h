#ifndef IFIELD_H_
#define IFIELD_H_

#include "IESAA.h"

#include <QString>
#include <string_view>
#include <any>
#include <initializer_list>
#include <QVariant>


#define Func_IsValid(Type) \
    bool isValid(Type data) const

#define Func_Format(Type) \
    bool format(Type data) const


template <class T>
class IDataType
{
    QString name_;
    QVector<T> data_;    //По умолчанию величина QVector == 1.
                         //Добавить возможность работать со списком.

public:
    IDataType() {};
    virtual ~IDataType() {};

    QString getName() const {
        return name_;
    };

    size_t getSize() const {
        return data_.size();
    };

    void addData(T data) {
        data_.push_back(data);
    };

    T getData(size_t i) const {
        return data_[i];
    };

    virtual Func_IsValid(T) = 0;
    virtual Func_Format(T) = 0;

//protected:
    IDataType(QString name) : name_(name) {};

};


#define FIELD_DATA_TYPE(Type) FIELD_DATA_TYPE_##Type
#define CAST_FIELD_DATA_TYPE(Type) ConvertTo##FIELD_DATA_TYPE_##Type
#define FIELD_DATA_TYPE_NAME(Type) ("FieldDataType_"#Type)


#define DEFINE_FIELD_DATA_TYPE(Type, Func_1, Code_1, Func_2, Code_2)    \
    class FIELD_DATA_TYPE(Type) : public IDataType<Type>                \
    {                                                                   \
    public:                                                             \
        FIELD_DATA_TYPE(Type)()                                         \
            : IDataType<Type>(FIELD_DATA_TYPE_NAME(Type)) {};           \
        virtual ~FIELD_DATA_TYPE(Type)() {};                            \
                                                                        \
    virtual Func_1 override Code_1;                                     \
    virtual Func_2 override Code_2;                                     \
    };                                                                  \
                                                                        \
    Q_DECLARE_METATYPE(FIELD_DATA_TYPE(Type))                           \
                                                                        \
    namespace CAST {                                                    \
        FIELD_DATA_TYPE(Type)                                           \
        CAST_FIELD_DATA_TYPE(Type)(QVariant& other) {                   \
           return other.value<FIELD_DATA_TYPE(Type)>();                 \
        }                                                               \
    }



class IField
{
    ID id_;
    QString name_;

    QVector<std::pair<QMetaType::Type, QVariant>> data_;

public:
    IField();
    virtual ~IField();

    void setId(int value);
    int getId() const;

    void setName(std::string_view value);
    QString getName() const;


    template<class T>
    void addData(T data) {
        QVariant var;
        var.setValue(data);
        data_.push_back(std::make_pair<QMetaType::Type, QVariant>(QMetaType::Type::Int, QVariant(var)));
    };

//    auto getData(size_t i) const {
//        return data_[i].second.value<data_[i].first>();
//    };

    auto getData(size_t i) const {
        return data_[i].second;
    };
};

#endif
