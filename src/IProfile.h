#ifndef IPROFILE_H_
#define IPROFILE_H_

#include "IField.h"

#include <QVector>




class Profile
{
    ID id_;

    QVector<Field*> fields_;  //TODO: Поменять на список, так как часто нужно менять элементы местами.

public:
    Profile();
    virtual ~Profile();

    void setId(ID id);
    ID getId() const;

    bool addField(Field* field);

    Field* getField(const QString& name) const;
    Field* getField(size_t i) const;

    QString getFieldName(size_t i) const;
    size_t fieldsCount() const;

    Profile* copy() const;
    Field* copyField(const QString& name) const;

    void clear();

    bool swap(size_t value1, size_t value2);
    bool move(size_t value, size_t target);

};




































//#define FindByName(Name) \



//class IProfile
//{
//    int id_;
//    QString name_;

//    QVector<QPair<ID, QVariant>> fields_;

//public:
//    IProfile();
//    virtual ~IProfile();

//    template<class T_Data, class T_Ui>
//    bool addField(IField<T_Data, T_Ui> field) {
//        QVariant var;
//        var.setValue(std::move(field));
//        fields_.push_back(QPair<ID, QVariant>(field.getId(), std::move(var)));
//        return true;
//    };

//    template<class T_Data, class T_Ui>
//    IField<T_Data, T_Ui> getField(ID id) const {
//        QVector<QPair<ID, QVariant>>::const_iterator dd;
//        dd = std::find_if(fields_.begin(), fields_.end(),
//                          [id](const QPair<ID, QVariant>& it) {
//            return it.first == id;
//        });

//        return dd->second.value<IField<T_Data, T_Ui>>();
//    };

//    template<class T_Data, class T_Ui>
//    IField<T_Data, T_Ui> getField(QString name) const {






//        bool a = fields_[0].second.canConvert<IField<T_Data, T_Ui>>();
//        bool b = fields_[1].second.canConvert<IField<T_Data, T_Ui>>();
//        return fields_[0].second.value<IField<T_Data, T_Ui>>();
//    };

//    ID getFieldTypeId(size_t i) const {
//        return fields_[i].first;
//    };

//    size_t size() const {
//        return fields_.size();
//    }

////    bool removeField(int i);

////    void setId(int value);
////    int getId();

//    void setName(QString value) {
//        name_ = value;
//    };

//    QString getName() const {
//        return name_;
//    };

//};

//#define DefConvertTo(DataType, Ui_Type)                                             \
//    IField<DataType, Ui_Type>                                                       \
//    CastTo##DataType##_##Ui_Type(IProfile& other) {                                 \
//       return other.getField<DataType, Ui_Type>(DATATYPE_ID(DataType, Ui_Type));    \
//    }





//class HumanProfile : public IProfile
//{

//public:
//    HumanProfile();
//    virtual ~HumanProfile();

////    virtual void setPhoto();
////    virtual void getPhoto();
////    virtual void removePhoto();

//};


//class ClientProfile : public HumanProfile
//{

//public:
//    ClientProfile();
//    virtual ~ClientProfile();

//};


//class EmployeeProfile : public HumanProfile
//{

//public:
//    EmployeeProfile();
//    virtual ~EmployeeProfile();

//    void setPost();
//    void getPost();

//};


//class GroupProfile : public IProfile
//{
//    QVector<ClientProfile*> clients_;

//public:
//    GroupProfile();
//    virtual ~GroupProfile();

//    void addClient(ClientProfile df);
//    const ClientProfile& getClient();
//    void removeClient(ClientProfile df);

//};

#endif
