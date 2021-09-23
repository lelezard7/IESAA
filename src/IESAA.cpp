#include "IESAAWindow.h"
#include "AuthorizationWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AuthorizationWindow authorizationWindow;

    if (authorizationWindow.exec() != QDialog::Accepted)
        return 0;

    IESAAWindow iesaa_window;
    iesaa_window.show();

    return a.exec();
}
