#include "FieldCreator.h"


#define StartGFG(Data) \
    switch(Data) {

#define EndGFG \
    }


#define GFG(DataType, DataUi, Name)                                         \
    case Name: {                                                            \
        auto data = new FIELD_DATA_TYPE(DataType, DataUi);                  \
        IField<DataType, DataUi>* field = new IField<DataType, DataUi>;     \
        field->setName(name.toStdString());                                 \
        field->addData(data);                                               \
        profile->addField(*field);                                          \
        break;                                                              \
    }

FieldCreator::
FieldCreator()
{

}

bool
FieldCreator::
addAssociation(QString name, int id)
{
    associations_.push_back(QPair<QString, int>(name, id));
    return true;
}

int
FieldCreator::
getId(QString name) const
{
    auto it = std::find_if(associations_.begin(), associations_.end(), [&name](const QPair<QString, int>& pair) {
        return name == pair.first;
    });

    return it->second;
}

void
FieldCreator::
addField(QString name, IProfile* profile, QString nameId)
{
    int id = getId(nameId);

    StartGFG(id)
            GFG(int, QSpinBox, DT_Int)
            GFG(QDate, QDateEdit, DT_Data)
    EndGFG
}
