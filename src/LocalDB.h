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

    virtual bool add(T* value);
    virtual T* get(size_t i) const;

    bool remove(size_t i);
    void clear();                           //TODO: В ProfileDataBase не освобождаются ID.

    qsizetype size() const;

};


class ProfileDataBase : public LocalDataBase<Profile>
{
    ONF::RangeIdManager<ID, long long> idManager_;

public:
    ProfileDataBase();
    virtual ~ProfileDataBase();

    virtual bool add(Profile* profile) override;

    bool removeById(ID id);
    Profile* findById(ID id) const;

};


class FieldDataBase : public LocalDataBase<Field>
{
public:
    FieldDataBase();
    virtual ~FieldDataBase();

    virtual bool add(Field* field) override;

    bool removeByName(QString name);
    Field* findByName(QString name) const;

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
