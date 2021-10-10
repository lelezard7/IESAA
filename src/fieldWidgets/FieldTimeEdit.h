#ifndef FIELDTIMEEDIT_H_
#define FIELDTIMEEDIT_H_

#include "IFieldWidget.h"

#include <QTimeEdit>


class FieldTimeEdit : public IFieldWidget
{
    QTimeEdit* timeEdit_;

public:
    FieldTimeEdit();
    FieldTimeEdit(QTimeEdit* timeEdit);
    FieldTimeEdit(FieldTimeEdit&& other) = delete;
    FieldTimeEdit(const FieldTimeEdit& other) = delete;
    virtual ~FieldTimeEdit();


    virtual bool setWidget(QWidget* widget) override;
    virtual QTimeEdit* getWidget() const override;

    virtual bool isWidgetSet() const override;

    virtual FieldTimeEdit* copy() const override;
    virtual QTimeEdit* copyWidget() const override;
    virtual QTimeEdit* associativeCopyWidget() const override;

    virtual bool setTextColor(const QColor& color) override;
    virtual QColor getTextColor() const override;

    virtual bool setBkColor(const QColor& color) override;
    virtual QColor getBkColor() const override;

    virtual void reset() override;
    virtual bool associateWith(QWidget* widget) const override;

};

#endif
