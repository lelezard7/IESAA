#ifndef PROFILECREATIONWINDOW_H_
#define PROFILECREATIONWINDOW_H_

#include "IESAA.h"
#include <QDialog>
#include <QString>
#include <memory>
#include "../../LocalDB.h"
#include "../../FieldCreator.h"
#include "../PFCreationWindow/PFCreationWindow.h"
#include "ProfileCreationHelper.h"
#include "IProfile.h"















namespace Ui
{
    class ProfileCreationWindow;
}


class ProfileCreationWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::ProfileCreationWindow* ui_;
    ProfileCreationHelper profileCreationHelper_;

    NamesSetsManager& namesSetsManager_;
    DefaultFieldsCreator& defaultFieldsCreator_;
    ProfileDataBase* profileDataBase_;



//    PFCreationWindow* pf_creationWindow_;

//    std::unique_ptr<IProfile> profile_;

public:
    explicit ProfileCreationWindow(
            NamesSetsManager& namesSetsManager,
            DefaultFieldsCreator& defaultFieldsCreator,
            FieldDataBase* defaultDB,
            ID id,
            ProfileDataBase* profileDataBase,
            QWidget* parent = nullptr);
    ~ProfileCreationWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_buttonBox_accepted();

//public slots:
//    void createRow(QString name, Field* field);

};

#endif
