#include "FieldsSettingsHelper.h"

#include <QCheckBox>


FieldsSettingsHelper::
FieldsSettingsHelper()
    : tableWidget_         (nullptr)
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
switchTo(const QString& name)
{
    tableWidget_->clearContents();
    tableWidget_->setRowCount(0);

    FieldDataBase* defaultFieldDB = defaultFieldDataBase_->getValue(name);
    size_t defaultFieldDBSize = defaultFieldDB->size();

    for (size_t i = 0; i < defaultFieldDBSize; ++i) {
        QWidget* newWidget = defaultFieldDB->getElement(i)->getWidget()->copyWidget();
        defaultFieldDB->getElement(i)->getWidget()->associateWith(newWidget);

        int rowCount = tableWidget_->rowCount();
        tableWidget_->insertRow(rowCount);

        tableWidget_->setCellWidget(rowCount, 0, new QCheckBox());
        tableWidget_->setCellWidget(rowCount, 2, newWidget);
        tableWidget_->setItem(rowCount, 1, new QTableWidgetItem(defaultFieldDB->getElement(i)->getName()));
    }
}
