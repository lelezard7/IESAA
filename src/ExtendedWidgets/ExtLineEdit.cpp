#include "ExtLineEdit.h"


ExtLineEdit::
ExtLineEdit()
    : QLineEdit()
    , LineEditExtension() {}

ExtLineEdit::
~ExtLineEdit() {}






template<class T>
IExtWidgetManager<T>::
IExtWidgetManager(T* widget)
    : QWidget()
    , widget_(widget) {}

template<class T>
IExtWidgetManager<T>::
IExtWidgetManager()
    : QWidget()
    , widget_(nullptr) {}

template<class T>
IExtWidgetManager<T>::
~IExtWidgetManager()
{
    if (widget_)
        delete widget_;
}

template<class T>
void
IExtWidgetManager<T>::
setWidget(T* widget)
{
    if (widget_)
        delete widget_;

    widget_ = widget;
}

template<class T>
T*
IExtWidgetManager<T>::
getWidget() const
{ return widget_; }

template<class T>
bool
IExtWidgetManager<T>::
isWidgetSet() const
{ return widget_ != nullptr; }

template<class T>
T*
IExtWidgetManager<T>::
associativeCopyWidget() const
{
    T* newWidget = copyWidget();

    if (!newWidget)
        return nullptr;

    associateWith(newWidget);
    return newWidget;
}







ExtLineEditManager::
ExtLineEditManager(ExtLineEdit* extLineEdit)
    : IExtWidgetManager<ExtLineEdit>(extLineEdit) {}

ExtLineEditManager::
ExtLineEditManager()
    : IExtWidgetManager<ExtLineEdit>(nullptr) {}

ExtLineEditManager::
~ExtLineEditManager() {}

ExtLineEdit*
ExtLineEditManager::
copyWidget() const
{
    ExtLineEdit* extLineEdit = getWidget();

    if (!extLineEdit)
        return nullptr;

    ExtLineEdit* newExtLineEdit = new ExtLineEdit;

    newExtLineEdit->setText(extLineEdit->text());
    newExtLineEdit->setStyleSheet(extLineEdit->styleSheet());
    return newExtLineEdit;
}

bool
ExtLineEditManager::
associateWith(ExtLineEdit* extLineEdit) const
{
    ExtLineEdit* thisExtLineEdit = getWidget();

    if (!extLineEdit || !thisExtLineEdit)
        return false;

    connect(extLineEdit, &ExtLineEdit::textChanged, thisExtLineEdit, &ExtLineEdit::setText);
    return true;
}
