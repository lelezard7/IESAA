#ifndef FIELDDATETIMEEDIT_H_
#define FIELDDATETIMEEDIT_H_

#include "FieldWidgets/IFieldWidget.h"

#include <QDateTimeEdit>


class FieldDateTimeEdit : public IFieldWidget
{
    QDateTimeEdit* dateTimeEdit_;

public:
    FieldDateTimeEdit();
    FieldDateTimeEdit(QDateTimeEdit* dateTimeEdit);
    FieldDateTimeEdit(FieldDateTimeEdit&& other) = delete;
    FieldDateTimeEdit(const FieldDateTimeEdit& other) = delete;
    virtual ~FieldDateTimeEdit();


    virtual bool setWidget(QWidget* widget) override;
    virtual QDateTimeEdit* getWidget() const override;

    virtual bool isWidgetSet() const override;

    virtual FieldDateTimeEdit* copy() const override;
    virtual QDateTimeEdit* copyWidget() const override;
    virtual QDateTimeEdit* associativeCopyWidget() const override;

    virtual bool setTextColor(const QColor& color) override;
    virtual QColor getTextColor() const override;

    virtual bool setBkColor(const QColor& color) override;
    virtual QColor getBkColor() const override;

    virtual void reset() override;
    virtual bool associateWith(QWidget* widget) const override;

};

#endif
