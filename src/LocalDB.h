#ifndef LOCALDB_H_
#define LOCALDB_H_

#include "IField.h"
#include "IProfile.h"
#include "../libs/ONF_v0.0.0/include/IdManagement.h"

// qsizetype
#include <QtGlobal>


template <class T>
class LocalDataBase
{
protected:
    QVector<T*> elements_;

public:
    LocalDataBase();
    virtual ~LocalDataBase();

    virtual bool addElement(T* value);
    virtual T* getElement(size_t i) const;
    virtual T* copyElement(size_t i) const;

    virtual bool remove(size_t i);
    virtual void clear();

    size_t size() const;

};


class ProfileDataBase : public LocalDataBase<Profile>
{
    ONF::RangeIdManager<ID, long long> idManager_;

public:
    ProfileDataBase();
    virtual ~ProfileDataBase();


    virtual bool addElement(Profile* profile) override;
    virtual Profile* copyElement(size_t i) const override;

    virtual bool remove(size_t i) override;
    virtual void clear() override;


    Profile* getElementById(ID id) const;
    Profile* copyElementById(ID id) const;
    bool removeById(ID id);

};


class FieldDataBase : public LocalDataBase<Field>
{
public:
    FieldDataBase();
    virtual ~FieldDataBase();


    virtual bool addElement(Field* field) override;
    virtual Field* copyElement(size_t i) const override;


    Field* copyElementByName(const QString& name) const;
    bool removeByName(const QString& name);
    Field* findByName(const QString& name) const;

};


#include "LocalDB.inl"




























//#include "IProfile.h"




//template <class T>
//class LocalDB
//{
//protected:
//    QVector<T> elements_;

//public:
//    LocalDB();
//    virtual ~LocalDB();

//    size_t size() const;

//    virtual bool add(T profile) = 0;
//    virtual T get(QString name) const = 0;

//};

//class ProfilesDB : public LocalDB<IProfile*>
//{
//public:
//    virtual bool add(IProfile* profile) override;
//    virtual IProfile* get(QString name) const override;

//};

//class FieldsDB
//{
//    std::unique_ptr<IProfile> fieldsContainer_;

//public:
//    FieldsDB();
//    virtual ~FieldsDB();

//    template <class T_Data, class T_Ui>
//    bool add(IField<T_Data, T_Ui>* field);

//    template <class T_Data, class T_Ui>
//    IField<T_Data, T_Ui>* get(QString name) const;

//};

//bool addStaff(IProfile* profile);
//IProfile* getStaff(QString name);

#endif
