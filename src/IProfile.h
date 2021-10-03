#ifndef IPROFILE_H_
#define IPROFILE_H_

#include "IField.h"

#include <QVector>


class IProfile
{
    int id_;
    QString name_;

    QVector<QPair<QString, QVariant>> fields_;

public:
    IProfile();
    virtual ~IProfile();

    template<class T_Data, class T_Ui>
    bool addField(IField<T_Data, T_Ui> field) {
        QVariant var;
        var.setValue(std::move(field));
        fields_.push_back(QPair<QString, QVariant>(field.getData(0)->getName(), std::move(var)));
        return true;
    };

    template<class T_Data, class T_Ui>
    IField<T_Data, T_Ui> getField(QString key) const {
        QVector<QPair<QString, QVariant>>::const_iterator dd = std::find_if(fields_.begin(), fields_.end(),
                         [key](const QPair<QString, QVariant>& it) {
            return it.first == key;
        });

        return dd->second.value<IField<T_Data, T_Ui>>();
    };

//    bool removeField(int i);

//    void setId(int value);
//    int getId();

    void setName(QString value) {
        name_ = value;
    };

    QString getName() const {
        return name_;
    };

};

#define DefConvertTo(DataType, Ui_Type) \
    IField<DataType, Ui_Type>                                                      \
    CastTo##DataType##_##Ui_Type(IProfile& other) {                                \
       return other.getField<DataType, Ui_Type>(FIELD_DATA_TYPE_NAME(DataType, Ui_Type));   \
    }





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
