#ifndef STATISTICSWINDOW_H_
#define STATISTICSWINDOW_H_

#include <QDialog>

namespace Ui
{
    class StatisticsWindow;
}


class StatisticsWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::StatisticsWindow* ui_;

public:
    explicit StatisticsWindow(QWidget* parent = nullptr);
    ~StatisticsWindow();

};

#endif
