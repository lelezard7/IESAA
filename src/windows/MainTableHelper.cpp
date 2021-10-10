#include "MainTableHelper.h"

#include <QTableWidgetItem>


MainTableHelper::
MainTableHelper()
    : tableWidget_           (nullptr)
    , profileDataBaseManager_(nullptr) {}

MainTableHelper::
MainTableHelper(QTableWidget* tableWidget, ProfileDataBaseManager* profileDBManager)
{
    tableWidget_ = tableWidget;
    profileDataBaseManager_ = profileDBManager;
}

MainTableHelper::
~MainTableHelper() {}

void
MainTableHelper::
setTableWidget(QTableWidget* tableWidget)
{
    tableWidget_ = tableWidget;
}

QTableWidget*
MainTableHelper::
getTableWidget() const
{
    return tableWidget_;
}

void
MainTableHelper::
setProfileDataBaseManager(ProfileDataBaseManager* profileDataBaseManager)
{
    profileDataBaseManager_ = profileDataBaseManager;
}

ProfileDataBaseManager*
MainTableHelper::
getProfileDataBaseManager() const
{
    return profileDataBaseManager_;
}

void
MainTableHelper::
insertColumn(int i, const QString& name)
{
    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText(name);

    tableWidget_->insertColumn(i);
    tableWidget_->setHorizontalHeaderItem(i, item);
}

void
MainTableHelper::
addColumn(const QString& name)
{
    insertColumn(tableWidget_->columnCount(), name);
}

void
MainTableHelper::
clear()
{
    tableWidget_->clearContents();
    tableWidget_->setRowCount(0);
}

void
MainTableHelper::
refreshClients()
{
    clear();

    ProfileDataBase* profileDataBase = profileDataBaseManager_->getValue("Клиенты");
    size_t profileCount = profileDataBase->size();

    for (size_t i = 0; i < profileCount; ++i) {
        drawProfile(profileDataBase->getElement(i));
    }
}



bool
MainTableHelper::
drawProfile(Profile* profile)
{
    int rowCount = tableWidget_->rowCount();
    tableWidget_->insertRow(rowCount);

    size_t fieldsCount = profile->fieldsCount();

    for (size_t i = 0; i < fieldsCount; ++i) {
        drawFeild(rowCount, profile->getField(i));
    }

    return true;
}

bool
MainTableHelper::
drawFeild(int row, Field* field)
{
    int columnCount = tableWidget_->columnCount();
    QString fieldName = field->getName();

    for (int i = 0; i < columnCount; ++i) {
        if (fieldName == tableWidget_->horizontalHeaderItem(i)->text()) {
            tableWidget_->setCellWidget(row, i, field->getWidget()->associativeCopyWidget());
            return true;
        }
    }

    insertColumn(columnCount, field->getName());
    tableWidget_->setCellWidget(row, columnCount, field->getWidget()->associativeCopyWidget());
//    tableWidget_->verticalHeader()->resizeSection(columnCount, 300);
    return true;
}
