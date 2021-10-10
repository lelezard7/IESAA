#ifndef PROFILECREATIONHELPER_H_
#define PROFILECREATIONHELPER_H_

#include "IProfile.h"
#include "LocalDB.h"
#include "WindowHelper.h"

#include <QTableWidget>


class ProfileCreationHelper : public WindowHelper
{
    QTableWidget* tableWidget_;
    FieldDataBase* defaultFieldDataBase_;
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

    virtual bool addField(Field* field) override;
    virtual bool addFieldToProfile(Field* field) override;
    virtual bool addFieldToDefaultFields(Field* field) override;

    bool removeField(const QString& name);

    void insertColumn(int i, const QString& name);
    void addColumn(const QString& name);

    void setIsEdit(bool value);
    bool isEdit();

    bool showDefaultFields();
    bool showProfileFields();

};

#endif
