#ifndef LOCALDB_H_
#define LOCALDB_H_

#include "IProfile.h"


class LocalDB
{
    QVector<IProfile*> profiles_;

public:
    LocalDB();
    virtual ~LocalDB();

    bool addProfile(IProfile* profile);
    IProfile* getProfile(QString name) const;

};

bool addStaff(IProfile* profile);
IProfile* getStaff(QString name);

#endif
