#ifndef AUTHORIZATIONWINDOW_H_
#define AUTHORIZATIONWINDOW_H_

#include <QDialog>


namespace Ui
{
    class AuthorizationWindow;
}


class AuthorizationWindow : public QDialog
{
    Q_OBJECT

private:
    bool isShowPass_;

    Ui::AuthorizationWindow *ui_;

public:
    explicit AuthorizationWindow(QWidget *parent = nullptr);
    ~AuthorizationWindow();

private slots:
    void on_lineEdit_Login_textEdited(const QString&);
    void on_lineEdit_Password_textEdited(const QString&);

    void on_pushButton_ShowPass_clicked();
    void on_pushButton_Apply_clicked();

private:
    void sendErrMessage(std::string_view message);
    void resetMessageField();

};

#endif
