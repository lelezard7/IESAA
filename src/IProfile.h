#ifndef IPROFILE_H_
#define IPROFILE_H_

#include "IField.h"

#include <QVector>


class IProfile
{
    int id_;
    QString name_;

    QVector<IField*> fields_;

public:
    IProfile();
    virtual ~IProfile();

    bool addField(IField* field);
    const IField& getField(int i);
    bool removeField(int i);

    void setId(int value);
    int getId();

    void setName(QString value);
    QString getName();

};


class HumanProfile : public IProfile
{

public:
    HumanProfile();
    virtual ~HumanProfile();

//    virtual void setPhoto();
//    virtual void getPhoto();
//    virtual void removePhoto();

};


class ClientProfile : public HumanProfile
{

public:
    ClientProfile();
    virtual ~ClientProfile();

};


class EmployeeProfile : public HumanProfile
{

public:
    EmployeeProfile();
    virtual ~EmployeeProfile();

    void setPost();
    void getPost();

};


class GroupProfile : public IProfile
{
    QVector<ClientProfile*> clients_;

public:
    GroupProfile();
    virtual ~GroupProfile();

    void addClient(ClientProfile df);
    const ClientProfile& getClient();
    void removeClient(ClientProfile df);

};

#endif
