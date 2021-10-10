#include "ProfileCreationWindow.h"
#include "ui_ProfileCreationWindow.h"



#include <QMessageBox>
#include <QComboBox>

















//static DefConvertTo(int, QSpinBox)
//static DefConvertTo(QDate, QDateEdit)


ProfileCreationWindow::
ProfileCreationWindow(
        NamesSetsManager& namesSetsManager,
        DefaultFieldsCreator& defaultFieldsCreator,
        FieldDataBase* defaultDB,
        ID id,
        ProfileDataBase* profileDataBase,
        QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::ProfileCreationWindow)
    , namesSetsManager_(namesSetsManager)
    , defaultFieldsCreator_(defaultFieldsCreator)
    , profileDataBase_(profileDataBase)
{
    ui_->setupUi(this);

    profileCreationHelper_.setTableWidget(ui_->tableWidget);
    profileCreationHelper_.setFieldDataBase(defaultDB);

    profileCreationHelper_.addColumn("Видимость");
    profileCreationHelper_.addColumn("Название");
    profileCreationHelper_.addColumn("Значение");

    ui_->tableWidget->horizontalHeader()->resizeSection(0, 80);
    ui_->tableWidget->horizontalHeader()->resizeSection(1, 200);
    ui_->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeMode::Stretch);

    if (id == ID_Null) {
        profileCreationHelper_.setProfile(new Profile);
        profileCreationHelper_.setIsEdit(false);
        profileCreationHelper_.showDefaultFields();
        return;
    }

    Profile* profile = profileDataBase_->getElementById(id);

    if (!profile) {                                                //TODO: Проверить на утечку памяти.
        QMessageBox messageBox(
                    "Профиль не найден.",
                    "Данный профиль не найден! Будет создан новый профиль.",
                    QMessageBox::Icon::Warning,
                    QMessageBox::StandardButton::Ok,
                    QMessageBox::StandardButton::NoButton,
                    QMessageBox::StandardButton::NoButton,
                    this);

        messageBox.exec();
        profileCreationHelper_.setProfile(new Profile);
        profileCreationHelper_.setIsEdit(false);
        profileCreationHelper_.showDefaultFields();
        return;
    }

    profileCreationHelper_.setProfile(profile);
    profileCreationHelper_.setIsEdit(true);
    profileCreationHelper_.showProfileFields();
}

ProfileCreationWindow::
~ProfileCreationWindow()
{
//    delete pf_creationWindow_;
    delete ui_;
}

void
ProfileCreationWindow::
on_pushButton_clicked()
{
    PFCreationWindow pf_creationWindow(
                namesSetsManager_,
                defaultFieldsCreator_,
                createFieldReceiver(profileCreationHelper_, ProfileCreationHelper::addField),
                this);
    pf_creationWindow.exec();
}

void
ProfileCreationWindow::
on_pushButton_2_clicked()
{
    PFCreationWindow pf_creationWindow(
                namesSetsManager_,
                defaultFieldsCreator_,
                createFieldReceiver(profileCreationHelper_, ProfileCreationHelper::addFieldToProfile),
                this);
    pf_creationWindow.exec();
}

void
ProfileCreationWindow::
on_buttonBox_accepted()
{
    if (profileCreationHelper_.isEdit())
        return;

    profileDataBase_->addElement(profileCreationHelper_.getProfile());
}
