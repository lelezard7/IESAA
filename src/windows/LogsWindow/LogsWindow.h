#ifndef LOGSWINDOW_H_
#define LOGSWINDOW_H_

#include <QDialog>

namespace Ui
{
    class LogsWindow;
}


class LogsWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::LogsWindow* ui_;

public:
    explicit LogsWindow(QWidget* parent = nullptr);
    ~LogsWindow();

};

#endif
