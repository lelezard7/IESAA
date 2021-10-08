#include "FieldCreator.h"

#include <QCheckBox>


TableManager::
TableManager()
    : tableWidget_(nullptr) {}

TableManager::
TableManager(QTableWidget* tableWidget)
    : tableWidget_(tableWidget) {}

TableManager::
~TableManager() {}

void
TableManager::
setTableWidget(QTableWidget* tableWidget)
{
    tableWidget_ = tableWidget;
}

QTableWidget*
TableManager::
getTableWidget() const
{
    return tableWidget_;
}

std::pair<int, int>
TableManager::
getSelectedCell() const
{
    return std::make_pair<int, int>(
                tableWidget_->selectedItems().at(0)->row(),
                tableWidget_->selectedItems().at(0)->column()
    );
}

void
TableManager::
insertColumn(int i, QString name)
{
    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText(name);

    tableWidget_->insertColumn(i);
    tableWidget_->setHorizontalHeaderItem(i, item);
}

void
TableManager::
insertRow(int i, QString name)
{
    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText(name);

    tableWidget_->insertRow(i);
    tableWidget_->setVerticalHeaderItem(i, item);
}

int
TableManager::
addColumn(QString name)
{
    int i = tableWidget_->columnCount();
    insertColumn(i, name);
    return i;
}

int
TableManager::
addRow(QString name)
{
    int i = tableWidget_->rowCount();
    insertRow(i, name);
    return i;
}

int
TableManager::
getColumIndex(QString name) const
{
    int columnCount = tableWidget_->columnCount();

    for (int i = 0; i < columnCount; ++i)
        if (name == tableWidget_->horizontalHeaderItem(i)->text())
            return i;

    return -1;
}

int
TableManager::
getRowIndex(QString name) const
{
    int rowCount = tableWidget_->rowCount();

    for (int i = 0; i < rowCount; ++i)
        if (name == tableWidget_->verticalHeaderItem(i)->text())
            return i;

    return -1;
}

QString
TableManager::
getColumName(int column) const
{
    return tableWidget_->horizontalHeaderItem(column)->text();
}

QString
TableManager::
getRowName(int row) const
{
    return tableWidget_->verticalHeaderItem(row)->text();
}

std::pair<int, int>
TableManager::
getIndices(QString rowName, QString columnName) const
{
    return std::make_pair<int, int>(getRowIndex(rowName), getColumIndex(columnName));
}

std::pair<QString, QString>
TableManager::
getName(int row, int column) const
{
    return std::make_pair<QString, QString>(getRowName(row), getColumName(column));
}

void
TableManager::
clear()
{
    tableWidget_->clear();
}

void
TableManager::
reset()
{
    tableWidget_->clearContents();
}

void
TableManager::
reset(QString rowName, QString columnName)
{
    tableWidget_->removeCellWidget(getRowIndex(rowName), getColumIndex(columnName));
}

void
TableManager::
reset(int row, int column)
{
    tableWidget_->removeCellWidget(row, column);
}

void
TableManager::
resetRow(QString name)
{
    resetRow(getRowIndex(name));
}

void
TableManager::
resetRow(int row)
{
    tableWidget_->removeRow(row);
}

void
TableManager::
resetColumn(QString name)
{
    resetColumn(getColumIndex(name));
}

void
TableManager::
resetColumn(int column)
{
    tableWidget_->removeColumn(column);
}

//void
//TableManager::
//setColor(int row, int column, const QColor& color)
//{
//}









TableManager_Profile::
TableManager_Profile()
    : tableWidget_(nullptr)
    , fieldDataBase_(nullptr) {}

TableManager_Profile::
TableManager_Profile(QTableWidget* tableWidget, FieldDataBase* fieldDataBase)
    : tableManager_(tableWidget)
    , tableWidget_(tableWidget)
    , fieldDataBase_(fieldDataBase) {}

TableManager_Profile::
~TableManager_Profile() {}

void
TableManager_Profile::
setTableWidget(QTableWidget* tableWidget)
{
    tableWidget_ = tableWidget;
    tableManager_.setTableWidget(tableWidget);
}

QTableWidget*
TableManager_Profile::
getTableWidget() const
{
    return tableWidget_;
}

void
TableManager_Profile::
setFieldDataBase(FieldDataBase* fieldDataBase)
{
    fieldDataBase_ = fieldDataBase;
}

FieldDataBase*
TableManager_Profile::
getFieldDataBase() const
{
    return fieldDataBase_;
}

TableManager&
TableManager_Profile::
ui()
{
    return tableManager_;
}

bool
TableManager_Profile::
addField(Field* field)
{
    if (!fieldDataBase_->addElement(field))
        return false;

    if (!field->fieldInfo().visibility)
        return true;

    int i = tableWidget_->rowCount();
    tableWidget_->insertRow(i);
    tableWidget_->setCellWidget(i, 0, new QCheckBox());
    tableWidget_->setCellWidget(i, 2, field->getWidget()->copyWidget());
    return true;
}

bool
TableManager_Profile::
removeField(QString name)
{

}

void
TableManager_Profile::
clearTableWidget()
{

}

void
TableManager_Profile::
clearFieldDataBase()
{

}

void
TableManager_Profile::
addColumn(int i, QString name)
{
    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText(name);

    tableWidget_->insertColumn(i);
    tableWidget_->setHorizontalHeaderItem(i, item);
}

void
TableManager_Profile::
addColumn(QString name)
{
    int i = tableWidget_->columnCount();
    addColumn(i, name);
}

void
TableManager_Profile::
addRow(int i, QString name)
{
    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText(name);

    tableWidget_->insertRow(i);
    tableWidget_->setVerticalHeaderItem(i, item);
}

void
TableManager_Profile::
addRow(QString name)
{
    int i = tableWidget_->rowCount();
    addRow(i, name);
}

void
TableManager_Profile::
refresh()
{
    tableWidget_->clear();
}

void
TableManager_Profile::
addFieldToTableWidget()
{

}
