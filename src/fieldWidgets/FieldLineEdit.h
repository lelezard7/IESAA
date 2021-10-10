#ifndef FIELDLINEEDIT_H_
#define FIELDLINEEDIT_H_

#include "IFieldWidget.h"

#include <QLineEdit>
#include <QString>
#include <QWidget>


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
    virtual QLineEdit* associativeCopyWidget() const override;

    virtual bool setTextColor(const QColor& color) override;
    virtual QColor getTextColor() const override;

    virtual bool setBkColor(const QColor& color) override;
    virtual QColor getBkColor() const override;

    virtual void reset() override;
    virtual bool associateWith(QWidget* widget) const override;

    bool setText(const QString& text);
    QString getText() const;

protected slots:                                   //TODO: Возможно нужно сделать public. Проверить.
    void event_textChanged(const QString &text);

};

#endif
