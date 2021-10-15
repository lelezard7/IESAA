#ifndef FIELDSSETTINGSHELPER_H_
#define FIELDSSETTINGSHELPER_H_

#include "AssociativePair.h"
#include "WindowHelper.h"

#include <QTableWidget>
#include <QLabel>


class FieldsSettingsHelper : public WindowHelper
{
    QLabel* infoLabel_;
    QTableWidget* tableWidget_;
    DefaultFieldDataBase* defaultFieldDataBase_;

    QString currentDataBase_;

public:
    FieldsSettingsHelper();
    virtual ~FieldsSettingsHelper();

    void setTableWidget(QTableWidget* tableWidget);
    QTableWidget* getTableWidget() const;

    void setDefaultFieldDataBase(DefaultFieldDataBase* defaultFieldDataBase);
    DefaultFieldDataBase* getDefaultFieldDataBase() const;

    void setInfoLabel(QLabel* infoLabel);
    QLabel* getInfoLabel() const;

    void insertColumn(int i, const QString& name);
    void addColumn(const QString& name);

    void setInfoToInfoLabel(size_t allFields, size_t activeFields, size_t inactiveFields);
    void switchTo(const QString& name);

    virtual AppError addField(Field* field) override;
    virtual AppError addFieldToProfile(Field* field) override;
    virtual AppError addFieldToDefaultFields(Field* field) override;

};

#endif
