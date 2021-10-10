#ifndef MAINTABLEHELPER_H_
#define MAINTABLEHELPER_H_

#include "AssociativePair.h"
#include "LocalDB.h"

#include <QTableWidget>
#include <QHeaderView>


class MainTableHelper
{
    QTableWidget* tableWidget_;
    ProfileDataBaseManager* profileDataBaseManager_;

public:
    MainTableHelper();
    MainTableHelper(QTableWidget* tableWidget, ProfileDataBaseManager* profileDBManager);
    virtual ~MainTableHelper();

    void setTableWidget(QTableWidget* tableWidget);
    QTableWidget* getTableWidget() const;

    void setProfileDataBaseManager(ProfileDataBaseManager* profileDataBaseManager);
    ProfileDataBaseManager* getProfileDataBaseManager() const;

    void insertColumn(int i, const QString& name);
    void addColumn(const QString& name);

    void clear();






    void refreshClients();


private:
    bool drawProfile(Profile* profile);
    bool drawFeild(int row, Field* field);

};

#endif
