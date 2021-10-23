#ifndef WIDGETEXTENSION_H_
#define WIDGETEXTENSION_H_

#include <QWidget>

class Field;


class IWidgetExtension
{
    Field* parentField_;

public:
    IWidgetExtension();
    virtual ~IWidgetExtension();

    void setParentField(Field* parentField);
    Field* getParentField() const;

    virtual void resetWidget() = 0;
    virtual void clearData() = 0;

    virtual bool setContentColor(const QColor& color) = 0;
    virtual QColor getContentColor() const = 0;

    virtual bool setBgColor(const QColor& color) = 0;
    virtual QColor getBgColor() const = 0;

};


#include <QLineEdit>

class LineEditExtension : public IWidgetExtension
{
public:
    LineEditExtension();
    virtual ~LineEditExtension();

    virtual void resetWidget() override;
    virtual void clearData() override;

    virtual bool setContentColor(const QColor& color) override;
    virtual QColor getContentColor() const override;

    virtual bool setBgColor(const QColor& color) override;
    virtual QColor getBgColor() const override;

};


#endif
