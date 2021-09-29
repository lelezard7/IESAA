#ifndef CLIENTCREATIONWINDOW_H_
#define CLIENTCREATIONWINDOW_H_

#include <QDialog>

namespace Ui
{
    class ClientCreationWindow;
}


class ClientCreationWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::ClientCreationWindow* ui_;

public:
    explicit ClientCreationWindow(QWidget* parent = nullptr);
    ~ClientCreationWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

};

#endif
