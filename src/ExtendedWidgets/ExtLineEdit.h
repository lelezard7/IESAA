#ifndef EXTLINEEDIT_H_
#define EXTLINEEDIT_H_

#include "WidgetExtension/WidgetExtension.h"

#include <QLineEdit>


class ExtLineEdit : public QLineEdit, public LineEditExtension
{
public:
    ExtLineEdit();
    virtual ~ExtLineEdit();

};





template<class T>
class IExtWidgetManager : public QWidget
{
private:
    T* widget_;

public:
    IExtWidgetManager(T* widget);
    IExtWidgetManager();
    virtual ~IExtWidgetManager();

    void setWidget(T* widget);
    T* getWidget() const;

    bool isWidgetSet() const;
    T* associativeCopyWidget() const;

    virtual T* copyWidget() const = 0;
    virtual bool associateWith(T* widget) const = 0;

};

class ExtLineEditManager : public IExtWidgetManager<ExtLineEdit>
{
    Q_OBJECT

public:
    ExtLineEditManager(ExtLineEdit* extLineEdit);
    ExtLineEditManager();
    virtual ~ExtLineEditManager();

    virtual ExtLineEdit* copyWidget() const override;
    virtual bool associateWith(ExtLineEdit* extLineEdit) const override;

};


#endif
