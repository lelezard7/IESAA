#ifndef AUTHORIZATIONWINDOW_H_
#define AUTHORIZATIONWINDOW_H_

#include "MessageBar.h"
#include "IESAAError.h"

#include <QDialog>
#include <QButtonGroup>

namespace Ui
{
    class AuthorizationWindow;
}


class AuthorizationWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::AuthorizationWindow *ui_;

    MessageBar messageBar_;
    IESAAError errCode_;
    bool isShowPass_;
    QButtonGroup bg_;

public:
    explicit AuthorizationWindow(QWidget* parent = nullptr);
    ~AuthorizationWindow();

private slots:
    void on_lineEdit_Login_textEdited(const QString&);
    void on_lineEdit_Password_textEdited(const QString&);

    void on_pushButton_ShowPass_clicked();
    void on_pushButton_Apply_clicked();

};

#endif
