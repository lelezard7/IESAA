#ifndef FIELDCHECKBOX_H_
#define FIELDCHECKBOX_H_

#include "IFieldWidget.h"

#include <QCheckBox>


class FieldCheckBox : public IFieldWidget
{
    QCheckBox* checkBox_;

public:
    FieldCheckBox();
    FieldCheckBox(QCheckBox* checkBox);
    FieldCheckBox(FieldCheckBox&& other) = delete;
    FieldCheckBox(const FieldCheckBox& other) = delete;
    virtual ~FieldCheckBox();


    virtual bool setWidget(QWidget* widget) override;
    virtual QCheckBox* getWidget() const override;

    virtual bool isWidgetSet() const override;

    virtual FieldCheckBox* copy() const override;
    virtual QCheckBox* copyWidget() const override;
    virtual QCheckBox* associativeCopyWidget() const override;

    virtual bool setTextColor(const QColor& color) override;
    virtual QColor getTextColor() const override;

    virtual bool setBkColor(const QColor& color) override;
    virtual QColor getBkColor() const override;

    virtual void reset() override;
    virtual bool associateWith(QWidget* widget) const override;

};

#endif
