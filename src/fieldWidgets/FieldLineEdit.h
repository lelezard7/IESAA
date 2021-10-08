#ifndef FIELDLINEEDIT_H_
#define FIELDLINEEDIT_H_

#include "IFieldWidget.h"

#include <QLineEdit>
#include <QString>


class FieldLineEdit : public IFieldWidget
{
    QLineEdit* lineEdit_;

public:
    FieldLineEdit();
    FieldLineEdit(QLineEdit* lineEdit);
    FieldLineEdit(FieldLineEdit&& other) = delete;
    FieldLineEdit(const FieldLineEdit& other) = delete;
    virtual ~FieldLineEdit();


    virtual bool setWidget(QWidget* widget) override;
    virtual QLineEdit* getWidget() const override;

    virtual bool isWidgetSet() const override;

    virtual FieldLineEdit* copy() const override;
    virtual QLineEdit* copyWidget() const override;

    virtual bool setTextColor(const QColor& color) override;
    virtual QColor getTextColor() const override;

    virtual bool setBkColor(const QColor& color) override;
    virtual QColor getBkColor() const override;

    virtual void reset() override;


    bool setText(const QString& text);
    QString getText() const;

};

#endif
