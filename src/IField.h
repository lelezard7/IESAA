#ifndef IFIELD_H_
#define IFIELD_H_

#include "IESAA.h"

#include <QString>
#include <string_view>
#include <any>
#include <initializer_list>
#include <QVariant>

#include <QTextEdit>
#include <QDateTimeEdit>
#include <QTableWidget>
#include <QLineEdit>

struct CellCoord
{
    int row;
    int column;
};


class IFieldWidget
{
    QWidget* widget_;

public:
    IFieldWidget() = delete;
    IFieldWidget(IFieldWidget&& other) = delete;
    IFieldWidget(const IFieldWidget& other) = delete;
    IFieldWidget(QWidget* widget);
    virtual ~IFieldWidget();

    bool setWidget(QWidget* widget);
    QWidget* getWidget() const;

    bool isWidgetValid() const;
    virtual void reset() = 0;

    virtual bool setTextColor(QColor& color) = 0;
    virtual bool setBkColor(QColor& color) = 0;

    virtual bool drawInTableWidget(QTableWidget& tableWidget, CellCoord cellCoord) const = 0;

    virtual IFieldWidget& operator=(const IFieldWidget& other) = 0;

//protected:
    virtual QWidget* copyWidget() const = 0;

};

class FieldLineEdit : public IFieldWidget
{
public:
    FieldLineEdit();
    FieldLineEdit(FieldLineEdit&& other) = delete;
    FieldLineEdit(const FieldLineEdit& other) = delete;
    FieldLineEdit(QLineEdit* lineEdit);
    virtual ~FieldLineEdit();

    virtual void reset() override;

    virtual bool setTextColor(QColor& color) override;
    virtual bool setBkColor(QColor& color) override;

    virtual bool drawInTableWidget(QTableWidget& tableWidget, CellCoord cellCoord) const override;

    virtual IFieldWidget& operator=(const IFieldWidget& other) override;
//    FieldLineEdit& operator=(FieldLineEdit&& other) = delete;
//    FieldLineEdit& operator=(const FieldLineEdit& other);

//protected:
    virtual QLineEdit* copyWidget() const override;

};


bool operator==(const FieldLineEdit& lValue, const FieldLineEdit& rValue);
bool operator!=(const FieldLineEdit& lValue, const FieldLineEdit& rValue);






//class FielTextEdit : public IFielWidget
//{
//    QTextEdit* textEdit_;


//    virtual void setWidget(QTextEdit* widget);

//public:
//    FielTextEdit();
//    virtual ~FielTextEdit();

//    virtual void setWidget(QWidget*) override;


//    virtual void setColor(QColor& color) override;
//    virtual QWidget* getWidget() override;







//class TTT : public IFieldWidget
//{
//public:
//    TTT() : IFieldWidget(new QLineEdit) {};
//    TTT(TTT&& other) = delete;
//    TTT(const TTT& other) = delete;
//    TTT(QLineEdit* lineEdit) : IFieldWidget(lineEdit) {};
//    virtual ~TTT() {};

//    virtual bool setTextColor(QColor& color) override {};
//    virtual bool setBkColor(QColor& color) override {};

//    virtual bool drawInTableWidget(QTableWidget& tableWidget, CellCoord cellCoord) const override {};


//protected:
//    virtual QLineEdit* copyWidget() const override {};

//};




struct FieldInfo
{
    FieldInfo();
    ~FieldInfo();

    bool visibility;
};




class Field
{
    QString name_;

    IFieldWidget* widget_;
    FieldInfo fieldInfo_;

public:
    Field();
    Field(std::string_view name, IFieldWidget* widget, FieldInfo fieldInfo = FieldInfo());
    virtual ~Field();

    bool setWidget(IFieldWidget* widget);
    IFieldWidget* getWidget() const;

    void setName(std::string_view name);
    QString getName() const;

    void setFieldInfo(const FieldInfo& fieldInfo);
    FieldInfo getFieldInfo() const;
    FieldInfo& fieldInfo();

    // operator=

};




class Profile
{
    ID id_;

    QVector<Field*> fields_;

public:
    Profile();
    virtual ~Profile();

    void setId(ID id);
    ID getId() const;

    bool addField(Field* field);

    Field* getField(QString name) const;
    Field* getField(size_t i) const;

    void clear();

    qsizetype fieldsCount() const;

//    bool swap(qsizetype value1, qsizetype value2);
//    bool move(qsizetype value, qsizetype target);

};
















//#define Func_SetStartState() \
//    void setStartStateUi()

//// Говорит как обрабатывать Ui исходя из данных в data_.
//#define Func_Refresh() \
//    void refresh()


//#define DataType_Id_int_QSpinBox      1
//#define DataType_Id_QDate_QDateEdit   2

//#define DATATYPE_ID(DataType, Ui_Type) DataType_Id_##DataType##_##Ui_Type

//template <class T, class T_Store>
//class DT_Iterator
//{
//    using Iterator = typename QVector<T>::Iterator;

//private:
//    Iterator it_;

//public:
//    DT_Iterator(T_Store* data)
//        : it_(nullptr) {
//        it_ = data->begin();
//    }

//    virtual ~DT_Iterator() {
//    }

//    DT_Iterator<T, T_Store>& operator++() {
//        ++it_;
//        return *this;
//    }

//    DT_Iterator<T, T_Store>& operator--() {
//        --it_;
//        return *this;
//    }

//    DT_Iterator<T, T_Store> operator++(int) {
//        Iterator prev = it_;
//        ++it_;
//        return prev;
//    }

//    DT_Iterator<T, T_Store> operator--(int) {
//        Iterator prev = it_;
//        --it_;
//        return prev;
//    }

//    DT_Iterator<T, T_Store>& operator+=(size_t n) {
//        it_ += n;
//        return *this;
//    }

//    DT_Iterator<T, T_Store>& operator-=(size_t n) {
//        it_ -= n;
//        return *this;
//    }

//    T& operator*() const {
//        return *it_;
//    }

//    bool operator==(const DT_Iterator<T, T_Store>& other) {
//        return it_ == other.it_;
//    }

//    bool operator!=(const DT_Iterator<T, T_Store>& other) {
//        return it_ != other.it_;
//    }

////    T* operator->() const {
////        return &(*it_);
////    }

//};




//template <class T_Data, class T_UiData>
//class IDataType
//{
//    ID id_;

//    QVector<T_Data*> data_;
//    QVector<T_UiData*> uiData_;

//public:
//    IDataType() = delete;
//    virtual ~IDataType();

//    ID getId() const;

//    size_t getDataSize() const;
//    size_t getUiDataSize() const;

//    void addData(T_Data* data);
//    void addUiData(T_UiData* data);

//    DT_Iterator<T_Data*, QVector<T_Data*>> dataBegin();
//    DT_Iterator<T_UiData*, QVector<T_UiData*>> uiDataBegin();

//    DT_Iterator<T_Data*, QVector<T_Data*>> dataEnd();
//    DT_Iterator<T_Data*, QVector<T_Data*>> uiDataEnd();

//    virtual Func_SetStartState() = 0;
//    virtual Func_Refresh() = 0;

//protected:
//    IDataType(ID id);

//};


//#define FIELD_DATA_TYPE(DataType, Ui_Type) FIELD_DATA_TYPE_##DataType##_##Ui_Type
//#define CAST_FIELD_DATA_TYPE(DataType, Ui_Type) ConvertTo##FIELD_DATA_TYPE_##DataType##_##Ui_Type
////#define FIELD_DATA_TYPE_NAME(DataType, Ui_Type) ("FieldDataType_"#DataType"_"#Ui_Type)

//class IProfile;

//template<class T_Data, class T_Ui>
//class IField;

//#define DEFINE_FIELD_DATA_TYPE(DataType, Ui_Type, Func_1, Code_1, Func_2, Code_2)      \
//    class FIELD_DATA_TYPE(DataType, Ui_Type) : public IDataType<DataType, Ui_Type>     \
//    {                                                                                  \
//    public:                                                                            \
//        FIELD_DATA_TYPE(DataType, Ui_Type)()                                           \
//            : IDataType<DataType, Ui_Type>(DATATYPE_ID(DataType, Ui_Type))             \
//        {                                                                              \
//            setStartStateUi();                                                         \
//        };                                                                             \
//        virtual ~FIELD_DATA_TYPE(DataType, Ui_Type)() {};                              \
//                                                                                       \
//        virtual Func_1 override Code_1;                                                \
//        virtual Func_2 override Code_2;                                                \
//    };                                                                                 \
//                                                                                       \
//    Q_DECLARE_METATYPE(FIELD_DATA_TYPE(DataType, Ui_Type))


//#include "IField.inl"




//template<class T_Data, class T_Ui>
//class IField
//{
//    ID id_;

//    QString name_;
//    QVector<IDataType<T_Data, T_Ui>*> data_;

//public:
//    IField() : id_(0) {};
//    virtual ~IField() {};

//    int getId() const {
//        return id_;
//    };

//    void setName(std::string_view value) {
//        name_ = value.data();
//    };

//    QString getName() const {
//        return name_;
//    };

//    void addData(IDataType<T_Data, T_Ui>* data) {
//        id_ = data->getId();
//        data_.push_back(data);
//    };

//    size_t size() const {
//        return data_.size();
//    }

//    DT_Iterator<IDataType<T_Data, T_Ui>*, QVector<IDataType<T_Data, T_Ui>*>> dataBegin() {
//        return &data_;
//    };

//    DT_Iterator<IDataType<T_Data, T_Ui>*, QVector<IDataType<T_Data, T_Ui>*>> dataEnd() {
//        return nullptr;
//    };

//};


////   ================== CustomZone ==================



//#include <QSpinBox>

//DEFINE_FIELD_DATA_TYPE(
//        int, QSpinBox,
//        Func_SetStartState(), {
//            QSpinBox* spinBox = new QSpinBox;
//            spinBox->setValue(0);
//            addUiData(spinBox);
//        },
//        Func_Refresh(), {
//            auto localDataIt = dataBegin();
//            auto spinBoxIt = uiDataBegin();
//            (*spinBoxIt)->setValue(**localDataIt);
//        }
//        )

//#include <QDate>
//#include <QDateEdit>

//DEFINE_FIELD_DATA_TYPE(
//        QDate, QDateEdit,
//        Func_SetStartState(), {
//            QDateEdit* dateEdit = new QDateEdit;
//            dateEdit->setDate(QDate());
//            addUiData(dateEdit);
//        },
//        Func_Refresh(), {
//            auto localData = dataBegin();
//            auto dateEdit = uiDataBegin();
//            (*dateEdit)->setDate(**localData);
//        }
//        )

#endif
