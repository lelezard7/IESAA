#include "LocalDB.h"


LocalDB::
LocalDB()
{

}

LocalDB::
~LocalDB()
{

}

bool
LocalDB::
addProfile(IProfile* profile)
{
    QVector<IProfile*>::const_iterator dd = std::find_if(profiles_.cbegin(), profiles_.cend(),
                     [profile](const IProfile* it) {
        return profile->getName() == it->getName();
    });

    if (dd != profiles_.cend())
        return false;

    profiles_.push_back(profile);
    return true;
}

IProfile*
LocalDB::
getProfile(QString name) const
{
    QVector<IProfile*>::const_iterator dd = std::find_if(profiles_.cbegin(), profiles_.cend(),
                     [&name](const IProfile* it) {
        return name == it->getName();
    });

    if (dd == profiles_.cend())
        return nullptr;

    return *dd;
}












static LocalDB staffDB;



bool
addStaff(IProfile* profile)
{
    return staffDB.addProfile(profile);
}

IProfile*
getStaff(QString name)
{
    return staffDB.getProfile(std::move(name));
}
