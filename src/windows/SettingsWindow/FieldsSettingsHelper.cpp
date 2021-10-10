#include "FieldsSettingsHelper.h"

#include <QCheckBox>


FieldsSettingsHelper::
FieldsSettingsHelper()
    : infoLabel_           (nullptr)
    , tableWidget_         (nullptr)
    , defaultFieldDataBase_(nullptr) {}

FieldsSettingsHelper::
~FieldsSettingsHelper() {}

void
FieldsSettingsHelper::
setTableWidget(QTableWidget* tableWidget)
{
    tableWidget_ = tableWidget;
}

QTableWidget*
FieldsSettingsHelper::
getTableWidget() const
{
    return tableWidget_;
}

void
FieldsSettingsHelper::
setDefaultFieldDataBase(DefaultFieldDataBase* defaultFieldDataBase)
{
    defaultFieldDataBase_ = defaultFieldDataBase;
}

DefaultFieldDataBase*
FieldsSettingsHelper::
getDefaultFieldDataBase() const
{
    return defaultFieldDataBase_;
}

void
FieldsSettingsHelper::
setInfoLabel(QLabel* infoLabel)
{
    infoLabel_ = infoLabel;
}

QLabel*
FieldsSettingsHelper::
getInfoLabel() const
{
    return infoLabel_;
}

void
FieldsSettingsHelper::
insertColumn(int i, const QString& name)
{
    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText(name);

    tableWidget_->insertColumn(i);
    tableWidget_->setHorizontalHeaderItem(i, item);
}

void
FieldsSettingsHelper::
addColumn(const QString& name)
{
    insertColumn(tableWidget_->columnCount(), name);
}

void
FieldsSettingsHelper::
setInfoToInfoLabel(size_t allFields, size_t activeFields, size_t inactiveFields)
{
    infoLabel_->setText(
                "<html>"
                    "<head><head/>"
                    "<body>"
                        "<p align=\"center\">Поля </p>"
                        "<p>"
                            "Всего: " + QString::number(allFields) + "<br/>"
                            "Активных: " + QString::number(activeFields) + "<br/>"
                            "Не активных: " + QString::number(inactiveFields) +
                        "</p>"
                    "</body>"
                "</html>"
                );
}

void
FieldsSettingsHelper::
switchTo(const QString& name)
{
    currentDataBase_ = name;

    size_t activeFields = 0;
    size_t inactiveFields = 0;

    tableWidget_->clearContents();
    tableWidget_->setRowCount(0);

    FieldDataBase* defaultFieldDB = defaultFieldDataBase_->getValue(name);
    size_t defaultFieldDBSize = defaultFieldDB->size();

    for (size_t i = 0; i < defaultFieldDBSize; ++i) {
        (defaultFieldDB->getElement(i)->fieldInfo().visibility) ? ++activeFields : ++inactiveFields;

        QWidget* newWidget = defaultFieldDB->getElement(i)->getWidget()->copyWidget();
        defaultFieldDB->getElement(i)->getWidget()->associateWith(newWidget);

        int rowCount = tableWidget_->rowCount();
        tableWidget_->insertRow(rowCount);

        tableWidget_->setCellWidget(rowCount, 0, new QCheckBox());
        tableWidget_->setCellWidget(rowCount, 2, newWidget);
        tableWidget_->setItem(rowCount, 1, new QTableWidgetItem(defaultFieldDB->getElement(i)->getName()));
    }

    setInfoToInfoLabel(defaultFieldDBSize, activeFields, inactiveFields);
}

bool
FieldsSettingsHelper::
addField(Field*)
{
//    if (!field)
//        return false;

//    if (tableWidget_->columnCount() < 3)
//        return false;

//    // add уже проверяет поля на повторение имен.
//    if (!defaultFieldDataBase_->getValue(currentDataBase_)->addElement(field->copy()))
//        return false;

//    // addField уже проверяет поля на повторение имен.
//    if (!profile_->addField(field))
//        return false;

//    if (!field->fieldInfo().visibility)
//        return true;

//    int i = tableWidget_->rowCount();
//    tableWidget_->insertRow(i);

//    QWidget* newWidget = field->getWidget()->copyWidget();
//    field->getWidget()->associateWith(newWidget);

//    tableWidget_->setCellWidget(i, 0, new QCheckBox());
//    tableWidget_->setCellWidget(i, 2, newWidget);
//    tableWidget_->setItem(i, 1, new QTableWidgetItem(field->getName()));
//    return true;
    return false;
}

bool
FieldsSettingsHelper::
addFieldToProfile(Field*)
{
//    if (!field)
//        return false;

//    if (tableWidget_->columnCount() < 3)
//        return false;

//    // addField уже проверяет поля на повторение имен.
//    if (!profile_->addField(field))
//        return false;

//    if (!field->fieldInfo().visibility)
//        return true;

//    int i = tableWidget_->rowCount();
//    tableWidget_->insertRow(i);

//    QWidget* newWidget = field->getWidget()->copyWidget();
//    field->getWidget()->associateWith(newWidget);

//    tableWidget_->setCellWidget(i, 0, new QCheckBox());
//    tableWidget_->setCellWidget(i, 2, newWidget);
//    tableWidget_->setItem(i, 1, new QTableWidgetItem(field->getName()));
//    return true;

    return false;
}

bool FieldsSettingsHelper::addFieldToDefaultFields(Field* field)
{
    if (!field)
        return false;

    if (tableWidget_->columnCount() < 3)
        return false;

    // add уже проверяет поля на повторение имен.
    if (!defaultFieldDataBase_->getValue(currentDataBase_)->addElement(field))
        return false;

    if (!field->fieldInfo().visibility)
        return true;

    int rowCount = tableWidget_->rowCount();
    tableWidget_->insertRow(rowCount);

    QWidget* newWidget = field->getWidget()->copyWidget();
    field->getWidget()->associateWith(newWidget);

    tableWidget_->setCellWidget(rowCount, 0, new QCheckBox());
    tableWidget_->setCellWidget(rowCount, 2, newWidget);
    tableWidget_->setItem(rowCount, 1, new QTableWidgetItem(field->getName()));
    return true;
}
