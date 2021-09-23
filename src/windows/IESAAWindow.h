#ifndef IESAAWINDOW_H_
#define IESAAWINDOW_H_

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class IESAAWindow;
}
QT_END_NAMESPACE


class IESAAWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::IESAAWindow* ui_;

public:
    IESAAWindow(QWidget *parent = nullptr);
    ~IESAAWindow();

};

#endif
