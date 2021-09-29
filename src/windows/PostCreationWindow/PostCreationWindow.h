#ifndef POSTCREATIONWINDOW_H_
#define POSTCREATIONWINDOW_H_

#include <QDialog>

namespace Ui
{
    class PostCreationWindow;
}


class PostCreationWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::PostCreationWindow* ui_;

public:
    explicit PostCreationWindow(QWidget* parent = nullptr);
    ~PostCreationWindow();

};

#endif
