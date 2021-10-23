#include "windows/IESAAWindow.h"
#include "windows/AuthorizationWindow/AuthorizationWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icons/app/ExeIcon"));

//    AuthorizationWindow authorizationWindow;

//    if (authorizationWindow.exec() != QDialog::Accepted)
//        return 0;

    IESAAWindow iesaa_window;
    iesaa_window.show();

    return a.exec();
}
