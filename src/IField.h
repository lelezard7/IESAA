#ifndef IFIELD_H_
#define IFIELD_H_

#include "IESAA.h"

#include <QString>
#include <string_view>
#include <any>
#include <initializer_list>
#include <QVariant>

#define Func_SetStartState() \
    void setStartStateUi()

// Говорит как обрабатывать Ui исходя из данных в data_.
#define Func_Refresh() \
    void refresh()


template <class T_Data, class T_Ui>
class IDataType
{
    QString name_;

    QVector<T_Data> data_;
    QVector<T_Ui*> dataUi_;

public:
    IDataType();
    virtual ~IDataType();

    QString getName() const;

    size_t getDataSize() const;
    size_t getDataUiSize() const;

    void addData(T_Data data);
    T_Data getData(size_t i) const;

    void addDataUi(T_Ui* data);
    T_Ui* getDataUi(size_t i) const;

    virtual Func_SetStartState() = 0;
    virtual Func_Refresh() = 0;

protected:
    IDataType(QString name);

};


#define FIELD_DATA_TYPE(DataType, Ui_Type) FIELD_DATA_TYPE_##DataType##_##Ui_Type
#define CAST_FIELD_DATA_TYPE(DataType, Ui_Type) ConvertTo##FIELD_DATA_TYPE_##DataType##_##Ui_Type
#define FIELD_DATA_TYPE_NAME(DataType, Ui_Type) ("FieldDataType_"#DataType"_"#Ui_Type)

class IProfile;

template<class T_Data, class T_Ui>
class IField;

#define DEFINE_FIELD_DATA_TYPE(DataType, Ui_Type, Func_1, Code_1, Func_2, Code_2)      \
    class FIELD_DATA_TYPE(DataType, Ui_Type) : public IDataType<DataType, Ui_Type>     \
    {                                                                                  \
    public:                                                                            \
        FIELD_DATA_TYPE(DataType, Ui_Type)()                                           \
            : IDataType<DataType, Ui_Type>(FIELD_DATA_TYPE_NAME(DataType, Ui_Type))    \
        {                                                                              \
            setStartStateUi();                                                         \
        };                                                                             \
        virtual ~FIELD_DATA_TYPE(DataType, Ui_Type)() {};                              \
                                                                                       \
        virtual Func_1 override Code_1;                                                \
        virtual Func_2 override Code_2;                                                \
    };                                                                                 \
                                                                                       \
    Q_DECLARE_METATYPE(FIELD_DATA_TYPE(DataType, Ui_Type))


#include "IField.inl"




template<class T_Data, class T_Ui>
class IField
{
    ID id_;
    QString name_;

    QVector<IDataType<T_Data, T_Ui>*> data_;

public:
    IField() : id_(0) {};
    virtual ~IField() {};

    void setId(int value) {
        id_ = value;
    };

    int getId() const {
        return id_;
    };

    void setName(std::string_view value) {
        name_ = value.data();
    };

    QString getName() const {
        return name_;
    };

    void addData(IDataType<T_Data, T_Ui>* data) {
        data_.push_back(data);
    };

    IDataType<T_Data, T_Ui>* getData(size_t i) const {
        return data_[i];
    };

};


//   ================== CustomZone ==================



#include <QSpinBox>

DEFINE_FIELD_DATA_TYPE(
        int, QSpinBox,
        Func_SetStartState(), {
            QSpinBox* spinBox = new QSpinBox;
            spinBox->setValue(0);
            addDataUi(spinBox);
        },
        Func_Refresh(), {
            int localData = getData(0);
            QSpinBox* spinBox = getDataUi(0);
            spinBox->setValue(localData);
        }
        )

#include <QDate>
#include <QDateEdit>

DEFINE_FIELD_DATA_TYPE(
        QDate, QDateEdit,
        Func_SetStartState(), {
            QDateEdit* dateEdit = new QDateEdit;
            dateEdit->setDate(QDate());
            addDataUi(dateEdit);
        },
        Func_Refresh(), {
            QDate localData = getData(0);
            QDateEdit* dateEdit = getDataUi(0);
            dateEdit->setDate(localData);
        }
        )

#endif
