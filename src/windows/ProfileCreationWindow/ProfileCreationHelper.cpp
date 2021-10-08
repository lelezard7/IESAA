#include "ProfileCreationHelper.h"

#include <QTableWidgetItem>
#include <QCheckBox>


ProfileCreationHelper::
ProfileCreationHelper()
    : tableWidget_  (nullptr)
    , defaultFieldDataBase_(nullptr)
    , profile_      (nullptr) {}

ProfileCreationHelper::
ProfileCreationHelper(QTableWidget* tableWidget, FieldDataBase* fieldDataBase, Profile* profile)
    : tableWidget_  (tableWidget)
    , defaultFieldDataBase_(fieldDataBase)
    , profile_      (profile) {}

ProfileCreationHelper::
~ProfileCreationHelper() {}

void
ProfileCreationHelper::
setTableWidget(QTableWidget* tableWidget)
{
    tableWidget_ = tableWidget;
}

QTableWidget*
ProfileCreationHelper::
getTableWidget() const
{
    return tableWidget_;
}

void
ProfileCreationHelper::
setFieldDataBase(FieldDataBase* fieldDataBase)
{
    defaultFieldDataBase_ = fieldDataBase;
}

FieldDataBase*
ProfileCreationHelper::
getFieldDataBase() const
{
    return defaultFieldDataBase_;
}

void
ProfileCreationHelper::
setProfile(Profile* profile)
{
    profile_ = profile;
}

Profile*
ProfileCreationHelper::
getProfile() const
{
    return profile_;
}

bool
ProfileCreationHelper::
addField(Field* field)
{
    if (!field)
        return false;

    if (tableWidget_->columnCount() < 3)
        return false;

    // add уже проверяет поля на повторение имен.
    if (!defaultFieldDataBase_->addElement(field->copy()))
        return false;

    // addField уже проверяет поля на повторение имен.
    if (!profile_->addField(field))
        return false;

    if (!field->fieldInfo().visibility)
        return true;

    int i = tableWidget_->rowCount();
    tableWidget_->insertRow(i);

    QWidget* newWidget = field->getWidget()->copyWidget();
    field->getWidget()->associateWith(newWidget);

    tableWidget_->setCellWidget(i, 0, new QCheckBox());
    tableWidget_->setCellWidget(i, 2, newWidget);
    tableWidget_->setItem(i, 1, new QTableWidgetItem(field->getName()));
    return true;
}

bool
ProfileCreationHelper::
addFieldToProfile(Field* field)
{
    if (!field)
        return false;

    if (tableWidget_->columnCount() < 3)
        return false;

    // addField уже проверяет поля на повторение имен.
    if (!profile_->addField(field))
        return false;

    if (!field->fieldInfo().visibility)
        return true;

    int i = tableWidget_->rowCount();
    tableWidget_->insertRow(i);

    QWidget* newWidget = field->getWidget()->copyWidget();
    field->getWidget()->associateWith(newWidget);

    tableWidget_->setCellWidget(i, 0, new QCheckBox());
    tableWidget_->setCellWidget(i, 2, newWidget);
    tableWidget_->setItem(i, 1, new QTableWidgetItem(field->getName()));
    return true;
}

bool
ProfileCreationHelper::
removeField(const QString& name)
{

}

void
ProfileCreationHelper::
insertColumn(int i, const QString& name)
{
    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText(name);

    tableWidget_->insertColumn(i);
    tableWidget_->setHorizontalHeaderItem(i, item);
}

void
ProfileCreationHelper::
addColumn(const QString& name)
{
    insertColumn(tableWidget_->columnCount(), name);
}

void
ProfileCreationHelper::
setIsEdit(bool value)
{
    isEdit_ = value;
}

bool
ProfileCreationHelper::
isEdit()
{
    return isEdit_;
}

bool
ProfileCreationHelper::
showDefaultFields()
{
    size_t fieldDataBaseSize = defaultFieldDataBase_->size();

    for (size_t i = 0; i < fieldDataBaseSize; ++i) {
        int rowCount = tableWidget_->rowCount();
        tableWidget_->insertRow(rowCount);

        tableWidget_->setCellWidget(rowCount, 0, new QCheckBox());
        tableWidget_->setCellWidget(rowCount, 2, defaultFieldDataBase_->getElement(i)->getWidget()->copyWidget());
        tableWidget_->setItem(rowCount, 1, new QTableWidgetItem(defaultFieldDataBase_->getElement(i)->getName()));

        profile_->addField(defaultFieldDataBase_->copyElement(i));
    }

    return true;
}

bool
ProfileCreationHelper::
showProfileFields()
{
    size_t fieldsCount = profile_->fieldsCount();

    for (size_t i = 0; i < fieldsCount; ++i) {
        int rowCount = tableWidget_->rowCount();
        tableWidget_->insertRow(rowCount);

        tableWidget_->setCellWidget(rowCount, 0, new QCheckBox());
        tableWidget_->setCellWidget(rowCount, 2, profile_->getField(i)->getWidget()->copyWidget());
        tableWidget_->setItem(rowCount, 1, new QTableWidgetItem(profile_->getField(i)->getName()));
    }

    return true;
}
