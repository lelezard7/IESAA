#ifndef FIELDCREATOR_H_
#define FIELDCREATOR_H_

#include "LocalDB.h"

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QVector>



class TableManager
{
    QTableWidget* tableWidget_;

public:
    TableManager();
    TableManager(QTableWidget* tableWidget);
    virtual ~TableManager();

    void setTableWidget(QTableWidget* tableWidget);
    QTableWidget* getTableWidget() const;

    std::pair<int, int> getSelectedCell() const;

    void insertColumn(int i, QString name);
    void insertRow(int i, QString name);

    int addColumn(QString name);
    int addRow(QString name);

    int getColumIndex(QString name) const;
    int getRowIndex(QString name) const;

    QString getColumName(int column) const;
    QString getRowName(int row) const;

    std::pair<int, int> getIndices(QString rowName, QString columnName) const;
    std::pair<QString, QString> getName(int row, int column) const;

    void clear();
    void reset();

    void reset(QString rowName, QString columnName);
    void reset(int row, int column);

    void resetRow(QString name);
    void resetRow(int row);

    void resetColumn(QString name);
    void resetColumn(int column);

//    void setColor(int row, int column, const QColor& color);

};

//FieldCreator

class TableManager_Profile
{
    TableManager tableManager_;
    QTableWidget* tableWidget_;
    FieldDataBase* fieldDataBase_;

public:
    TableManager_Profile();
    TableManager_Profile(QTableWidget* tableWidget, FieldDataBase* fieldDataBase = nullptr);
    virtual ~TableManager_Profile();

    void setTableWidget(QTableWidget* tableWidget);
    QTableWidget* getTableWidget() const;

    void setFieldDataBase(FieldDataBase* fieldDataBase);
    FieldDataBase* getFieldDataBase() const;

    TableManager& ui();

    bool addField(Field* field);
    bool removeField(QString name);

    void clearTableWidget();
    void clearFieldDataBase();

    void addColumn(int i, QString name);
    void addColumn(QString name);

    void addRow(int i, QString name);
    void addRow(QString name);

    void refresh();

protected:
    void addFieldToTableWidget();

};


















//#define FC_Case(DataType, DataUi)                                           \
//    case DATATYPE_ID(DataType, DataUi): {                                   \
//        auto data = new FIELD_DATA_TYPE(DataType, DataUi);                  \
//        IField<DataType, DataUi>* field = new IField<DataType, DataUi>;     \
//        field->setName(name.toStdString());                                 \
//        field->addData(data);                                               \
//        profile->addField(*field);                                          \
//        break;                                                              \
//    }

//#define FC_Assotiation(Name, Id) \
//    associations_.push_back(QPair<QString, ID>(Name, Id));


//#define CreateFieldCreator(Assotiations, Cases)                              \
//class FieldCreator                                                           \
//{                                                                            \
//    QVector<QPair<QString, ID>> associations_;                               \
//                                                                             \
//public:                                                                      \
//    FieldCreator() {                                                         \
//        Assotiations                                                         \
//    };                                                                       \
//                                                                             \
//    bool addAssociation(QString name, ID id) {                               \
//        associations_.push_back(QPair<QString, int>(name, id));              \
//        return true;                                                         \
//    };                                                                       \
//                                                                             \
//    int getId(QString name) const {                                          \
//        auto it = std::find_if(associations_.begin(), associations_.end(),   \
//                               [&name](const QPair<QString, int>& pair) {    \
//            return name == pair.first;                                       \
//        });                                                                  \
//                                                                             \
//        return it->second;                                                   \
//    };                                                                       \
//                                                                             \
//    size_t size() const {                                                    \
//        return associations_.size();                                         \
//    }                                                                        \
//                                                                             \
//    QString getName(size_t i) const {                                        \
//        return associations_[i].first;                                       \
//    }                                                                        \
//                                                                             \
//    void addField(QString name, IProfile* profile, QString nameId) {         \
//        int id = getId(nameId);                                              \
//                                                                             \
//        switch(id) {                                                         \
//            Cases                                                            \
//        }                                                                    \
//    };                                                                       \
//                                                                             \
//};


//CreateFieldCreator(
//        //Поля создаваемые в comboBox
//        FC_Assotiation("Число", DATATYPE_ID(int, QSpinBox))
//        FC_Assotiation("Дата", DATATYPE_ID(QDate, QDateEdit))
//        /*associations_.size();  - Так не должно быть. Это должно быть ошибкой.*/,

//        //Тип данных и поля
//        FC_Case(int, QSpinBox)
//        FC_Case(QDate, QDateEdit)
//)


//#undef FC_Assotiation
//#undef FC_Case
//#undef CreateFieldCreator

#endif
