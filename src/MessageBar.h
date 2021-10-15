#ifndef MESSAGEBAR_H_
#define MESSAGEBAR_H_

#include "StyleSheetCreator.h"

#include <QWidget>
#include <QString>
#include <QLabel>

namespace Ui
{
    class AuthorizationWindow;
}


class MessageBar
{
    QLabel* messageBar_;

    bool isFreeze_;

public:
    MessageBar(QLabel* messageBar = nullptr);
    virtual ~MessageBar();

    void setMessageBar(QLabel* messageBar);
    QLabel* getMessageBar() const;

    bool setInfoMessage(const QString& message);
    bool setWarningMessage(const QString& message);
    bool setErrorMessage(const QString& message);
    QString getMessage() const;

    bool resetMessage(const QString& message);
    bool resetMessage();
    void reset();

    void freeze(bool value);
    bool isFreeze() const;

protected:
    bool setMessage(const QString& message, StyleSheetCreator* styleSheetCreator);

};

#endif
