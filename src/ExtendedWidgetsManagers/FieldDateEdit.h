#ifndef FIELDDATEEDIT_H_
#define FIELDDATEEDIT_H_

#include "ExtendedWidgetsManagers/IFieldWidget.h"

#include <QDateEdit>


class FieldDateEdit : public IFieldWidget
{
    QDateEdit* dateEdit_;

public:
    FieldDateEdit();
    FieldDateEdit(QDateEdit* dateEdit);
    FieldDateEdit(FieldDateEdit&& other) = delete;
    FieldDateEdit(const FieldDateEdit& other) = delete;
    virtual ~FieldDateEdit();


    virtual bool setWidget(QWidget* widget) override;
    virtual QDateEdit* getWidget() const override;

    virtual bool isWidgetSet() const override;

    virtual FieldDateEdit* copy() const override;
    virtual QDateEdit* copyWidget() const override;
    virtual QDateEdit* associativeCopyWidget() const override;

    virtual bool setTextColor(const QColor& color) override;
    virtual QColor getTextColor() const override;

    virtual bool setBkColor(const QColor& color) override;
    virtual QColor getBkColor() const override;

    virtual void reset() override;
    virtual bool associateWith(QWidget* widget) const override;

};

#endif
