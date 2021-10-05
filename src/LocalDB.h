#ifndef LOCALDB_H_
#define LOCALDB_H_

#include "IField.h"

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
    void clear();

    qsizetype size() const;

};


class ProfileDataBase : public LocalDataBase<Profile>
{
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







class DefaultFieldManager
{
    using Category = std::pair<QString, FieldDataBase*>;

private:
    QVector<Category> db_;

public:
    DefaultFieldManager();
    virtual ~DefaultFieldManager();

    bool createCategory(QString name);
    bool deleteCategory(QString name);

    Category getCategory(size_t i) const;
    FieldDataBase* find(QString name) const;
    size_t size() const;

    bool remove(QString name);
    void clear();

};























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
