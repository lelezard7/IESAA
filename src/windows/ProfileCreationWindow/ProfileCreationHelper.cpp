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

AppError
ProfileCreationHelper::
addField(Field* field)
{
    if (!field)
        return AppError(ErrCode_Undefined, "");

    if (tableWidget_->columnCount() < 3)
        return AppError(ErrCode_Undefined, "");

    if (defaultFieldDataBase_->findByName(field->getName()))
        return AppError(ErrCode_FieldAlreadyExists, "Поле по умолчанию с таким названием уже существует!");

    if (profile_->getField(field->getName()))
        return AppError(ErrCode_FieldAlreadyExists, "Поле с таким названием уже существует в профиле!");

    defaultFieldDataBase_->addElement(field->copy());
    profile_->addField(field);

    if (!field->fieldInfo().visibility)
        return AppError();

    int i = tableWidget_->rowCount();
    tableWidget_->insertRow(i);

    QWidget* newWidget = field->getWidget()->copyWidget();
    field->getWidget()->associateWith(newWidget);

    tableWidget_->setCellWidget(i, 0, new QCheckBox());
    tableWidget_->setCellWidget(i, 2, newWidget);
    tableWidget_->setItem(i, 1, new QTableWidgetItem(field->getName()));
    return AppError();
}

AppError
ProfileCreationHelper::
addFieldToProfile(Field* field)
{
    if (!field)
        return AppError(ErrCode_Undefined, "");

    if (tableWidget_->columnCount() < 3)
        return AppError(ErrCode_Undefined, "");

    // addField уже проверяет поля на повторение имен.
    if (!profile_->addField(field))
        return AppError(ErrCode_FieldAlreadyExists, "Поле с таким названием уже существует в профиле!");

    if (!field->fieldInfo().visibility)
        return AppError();

    int i = tableWidget_->rowCount();
    tableWidget_->insertRow(i);

    QWidget* newWidget = field->getWidget()->copyWidget();
    field->getWidget()->associateWith(newWidget);

    tableWidget_->setCellWidget(i, 0, new QCheckBox());
    tableWidget_->setCellWidget(i, 2, newWidget);
    tableWidget_->setItem(i, 1, new QTableWidgetItem(field->getName()));
    return AppError();
}

AppError
ProfileCreationHelper::
addFieldToDefaultFields(Field*)
{
    return AppError(ErrCode_Undefined, "");                      //TODO: Должен обрабатывать.
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

        Field* field = defaultFieldDataBase_->copyElement(i);

        tableWidget_->setCellWidget(rowCount, 0, new QCheckBox());
        tableWidget_->setCellWidget(rowCount, 2, field->getWidget()->associativeCopyWidget());
        tableWidget_->setItem(rowCount, 1, new QTableWidgetItem(defaultFieldDataBase_->getElement(i)->getName()));

        profile_->addField(field);
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
        tableWidget_->setCellWidget(rowCount, 2, profile_->getField(i)->getWidget()->associativeCopyWidget());
        tableWidget_->setItem(rowCount, 1, new QTableWidgetItem(profile_->getField(i)->getName()));
    }

    return true;
}
