#include "IField.h"


template <class T_Data, class T_Ui>
IDataType<T_Data, T_Ui>::
IDataType() {}; //По умолчанию величина QVector == 1.
                //Добавить возможность работать со списком.

template <class T_Data, class T_Ui>
IDataType<T_Data, T_Ui>::
~IDataType() {};

template <class T_Data, class T_Ui>
QString
IDataType<T_Data, T_Ui>::
getName() const
{
    return name_;
}

template <class T_Data, class T_Ui>
size_t
IDataType<T_Data, T_Ui>::
getDataSize() const
{
    return data_.size();
}

template <class T_Data, class T_Ui>
size_t
IDataType<T_Data, T_Ui>::
getDataUiSize() const
{
    return dataUi_.size();
}

template <class T_Data, class T_Ui>
void
IDataType<T_Data, T_Ui>::
addData(T_Data data)
{
    data_.push_back(data);
}

template <class T_Data, class T_Ui>
T_Data
IDataType<T_Data, T_Ui>::
getData(size_t i) const
{
    return data_[i];
}

template <class T_Data, class T_Ui>
void
IDataType<T_Data, T_Ui>::
addDataUi(T_Ui* data)
{
    dataUi_.push_back(data);
}

template <class T_Data, class T_Ui>
T_Ui*
IDataType<T_Data, T_Ui>::
getDataUi(size_t i) const
{
    return dataUi_[i];
}

template <class T_Data, class T_Ui>
IDataType<T_Data, T_Ui>::
IDataType(QString name)
    : name_(name) {};
