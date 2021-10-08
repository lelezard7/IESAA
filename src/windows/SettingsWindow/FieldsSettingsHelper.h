#ifndef FIELDSSETTINGSHELPER_H_
#define FIELDSSETTINGSHELPER_H_

#include "AssociativePair.h"

#include <QTableWidget>


class FieldsSettingsHelper
{
    QTableWidget* tableWidget_;
    DefaultFieldDataBase* defaultFieldDataBase_;

public:
    FieldsSettingsHelper();
    virtual ~FieldsSettingsHelper();

    void setTableWidget(QTableWidget* tableWidget);
    QTableWidget* getTableWidget() const;

    void setDefaultFieldDataBase(DefaultFieldDataBase* defaultFieldDataBase);
    DefaultFieldDataBase* getDefaultFieldDataBase() const;

    void insertColumn(int i, const QString& name);
    void addColumn(const QString& name);

    void switchTo(const QString& name);

};

#endif
