#ifndef PROFILECREATIONWINDOW_H_
#define PROFILECREATIONWINDOW_H_

#include <QDialog>
#include <memory>
#include "../../LocalDB.h"
#include "../PFCreationWindow/FieldCreator.h"
//#include "../PFCreationWindow/PFCreationWindow.h"















namespace Ui
{
    class ProfileCreationWindow;
}


class ProfileCreationWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::ProfileCreationWindow* ui_;
    FieldCreator fieldCreator_;




//    PFCreationWindow* pf_creationWindow_;

//    std::unique_ptr<IProfile> profile_;

public:
    explicit ProfileCreationWindow(FieldDataBase* defaultDB, QWidget* parent = nullptr);
    ~ProfileCreationWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_buttonBox_accepted();

};

#endif
