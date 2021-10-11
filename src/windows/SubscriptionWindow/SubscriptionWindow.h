#ifndef SUBSCRIPTIONWINDOW_H_
#define SUBSCRIPTIONWINDOW_H_

#include <QDialog>


namespace Ui
{
    class SubscriptionWindow;
}

class SubscriptionWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::SubscriptionWindow* ui_;

public:
    explicit SubscriptionWindow(QWidget* parent = nullptr);
    ~SubscriptionWindow();

};

#endif
