#ifndef FIELDCREATOR_H_
#define FIELDCREATOR_H_

#include "../../LocalDB.h"

#include <QVector>

#define DT_Int  0x00000001
#define DT_Data 0x00000002

class FieldCreator
{
    QVector<QPair<QString, int>> associations_;

public:
    FieldCreator();

    bool addAssociation(QString name, int id);
    int getId(QString name) const;
    void addField(QString name, IProfile* profile, QString nameId);

};

#endif
