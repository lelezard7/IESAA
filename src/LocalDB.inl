#include "LocalDB.h"


template<class T>
LocalDataBase<T>::
LocalDataBase() {}

template<class T>
LocalDataBase<T>::
~LocalDataBase()
{
    qsizetype elementsSize = elements_.size();

    for (qsizetype i = 0; i < elementsSize; ++i)
        delete elements_[i];

    elements_.clear();
}

template<class T>
bool
LocalDataBase<T>::
addElement(T* value)
{
    if (!value)
        return false;

    elements_.push_back(value);
    return true;
}

template<class T>
T*
LocalDataBase<T>::
getElement(size_t i) const
{
    if (i >= static_cast<size_t>(elements_.size()))
        return nullptr;

    return elements_[i];
}

template<class T>
T*
LocalDataBase<T>::
copyElement(size_t i) const
{
    if (i >= static_cast<size_t>(elements_.size()))
        return nullptr;

    T* newElement = new T;
    *newElement = *(elements_[i]);
    return newElement;
}

template<class T>
bool
LocalDataBase<T>::
remove(size_t i)
{
    if (i >= static_cast<size_t>(elements_.size()))
        return false;

    delete elements_[i];
    elements_.remove(i);            //TODO: Проверить. До этого я использовал только erase.
    return true;
}

template<class T>
void
LocalDataBase<T>::
clear()
{
    qsizetype elementsSize = elements_.size();

    for (qsizetype i = 0; i < elementsSize; ++i)
        delete elements_[i];

    elements_.clear();
}

template<class T>
size_t
LocalDataBase<T>::
size() const
{
    return elements_.size();
}
