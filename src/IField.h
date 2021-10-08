#ifndef IFIELD_H_
#define IFIELD_H_

#include "IESAA.h"
#include "FieldWidgets.h"

#include <QString>
#include <string_view>
#include <any>
#include <initializer_list>
#include <QVariant>

#include <QTextEdit>
#include <QDateTimeEdit>
#include <QTableWidget>
#include <QLineEdit>

















struct FieldInfo
{
    FieldInfo();
    ~FieldInfo();

    bool visibility;
};




class Field
{
    QString name_;

    IFieldWidget* widget_;
    FieldInfo fieldInfo_;

public:
    Field();
    Field(const QString& name, IFieldWidget* widget, FieldInfo fieldInfo = FieldInfo());
    virtual ~Field();

    bool setWidget(IFieldWidget* widget);
    IFieldWidget* getWidget() const;

    void setName(const QString& name);
    QString getName() const;

    Field* copy() const;

    void setFieldInfo(const FieldInfo& fieldInfo);
    FieldInfo getFieldInfo() const;
    FieldInfo& fieldInfo();

    // operator=

};





#endif
