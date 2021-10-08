#ifndef PROFILECREATIONHELPER_H_
#define PROFILECREATIONHELPER_H_

#include "IProfile.h"
#include "LocalDB.h"

#include <QTableWidget>


class ProfileCreationHelper
{
    QTableWidget* tableWidget_;
    FieldDataBase* fieldDataBase_;
    Profile* profile_;

    bool isEdit_;

public:
    ProfileCreationHelper();
    ProfileCreationHelper(QTableWidget* tableWidget, FieldDataBase* fieldDataBase, Profile* profile);
    virtual ~ProfileCreationHelper();

    void setTableWidget(QTableWidget* tableWidget);
    QTableWidget* getTableWidget() const;

    void setFieldDataBase(FieldDataBase* fieldDataBase);
    FieldDataBase* getFieldDataBase() const;

    void setProfile(Profile* profile);
    Profile* getProfile() const;

    bool addField(Field* field);
    bool addFieldToProfile(Field* field);
    bool addFieldToDefaultField(Field* field);

    bool removeField(const QString& name);

    void insertColumn(int i, const QString& name);
    void addColumn(const QString& name);

    void setIsEdit(bool value);
    bool isEdit();

    bool showDefaultFields();
    bool showProfileFields();

};

#endif
