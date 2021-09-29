#ifndef ABOUTIESAAWINDOW_H_
#define ABOUTIESAAWINDOW_H_

#include <QDialog>

namespace Ui
{
    class AboutIESAAWindow;
}


class AboutIESAAWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::AboutIESAAWindow* ui_;

public:
    explicit AboutIESAAWindow(QWidget* parent = nullptr);
    ~AboutIESAAWindow();

};

#endif
