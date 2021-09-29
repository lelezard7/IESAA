#ifndef MESSAGEBAR_H_
#define MESSAGEBAR_H_

#include <QString>

namespace Ui
{
    class AuthorizationWindow;
}


class MessageBar
{
    Ui::AuthorizationWindow *ui_;

    bool isFreeze_;

public:
    MessageBar(Ui::AuthorizationWindow* ui = nullptr);
    virtual ~MessageBar();

    bool setMessage(std::string_view message);
    QString getMessage() const;

    bool resetMessage();

    void freeze(bool value);
    bool isFreeze() const;

};

#endif
