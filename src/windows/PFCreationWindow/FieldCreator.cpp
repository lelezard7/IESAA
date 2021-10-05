#include "FieldCreator.h"


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

void
TableManager::
addColumn(QString name)
{
    int i = tableWidget_->columnCount();
    insertColumn(i, name);
}

void
TableManager::
addRow(QString name)
{
    int i = tableWidget_->rowCount();
    insertRow(i, name);
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









FieldCreator::
FieldCreator()
    : tableWidget_(nullptr)
    , fieldDataBase_(nullptr) {}

FieldCreator::
FieldCreator(QTableWidget* tableWidget, FieldDataBase* fieldDataBase)
    : tableWidget_(tableWidget)
    , fieldDataBase_(fieldDataBase) {}

FieldCreator::
~FieldCreator() {}

void
FieldCreator::
setTableWidget(QTableWidget* tableWidget)
{
    tableWidget_ = tableWidget;
}

QTableWidget*
FieldCreator::
getTableWidget() const
{
    return tableWidget_;
}

void
FieldCreator::
setFieldDataBase(FieldDataBase* fieldDataBase)
{
    fieldDataBase_ = fieldDataBase;
}

FieldDataBase*
FieldCreator::
getFieldDataBase() const
{
    return fieldDataBase_;
}

bool
FieldCreator::
addField(Field* field)
{
    return fieldDataBase_->add(field);
}

bool
FieldCreator::
removeField(QString name)
{

}

void
FieldCreator::
clearTableWidget()
{

}

void
FieldCreator::
clearFieldDataBase()
{

}

void
FieldCreator::
addColumn(int i, QString name)
{
    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText(name);

    tableWidget_->insertColumn(i);
    tableWidget_->setHorizontalHeaderItem(i, item);
}

void
FieldCreator::
addColumn(QString name)
{
    int i = tableWidget_->columnCount();
    addColumn(i, name);
}

void
FieldCreator::
addRow(int i, QString name)
{
    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText(name);

    tableWidget_->insertRow(i);
    tableWidget_->setVerticalHeaderItem(i, item);
}

void
FieldCreator::
addRow(QString name)
{
    int i = tableWidget_->rowCount();
    addRow(i, name);
}

void
FieldCreator::
refresh()
{
    tableWidget_->clear();
}

void
FieldCreator::
addFieldToTableWidget()
{

}
