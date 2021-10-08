#ifndef IFIELDWIDGET_H_
#define IFIELDWIDGET_H_

#include <QWidget>


class IFieldWidget : public QWidget
{
    Q_OBJECT

public:
    virtual ~IFieldWidget() = default;

    virtual bool setWidget(QWidget* widget) = 0;
    virtual QWidget* getWidget() const = 0;

    virtual bool isWidgetSet() const = 0;

    virtual IFieldWidget* copy() const = 0;
    virtual QWidget* copyWidget() const = 0;

    virtual bool setTextColor(const QColor& color) = 0;
    virtual QColor getTextColor() const = 0;

    virtual bool setBkColor(const QColor& color) = 0;
    virtual QColor getBkColor() const = 0;

    virtual void reset() = 0;
    virtual bool associateWith(QWidget* widget) = 0;

    virtual IFieldWidget& operator=(IFieldWidget&& other) = delete;
    virtual IFieldWidget& operator=(const IFieldWidget& other) = delete;

};

#endif
