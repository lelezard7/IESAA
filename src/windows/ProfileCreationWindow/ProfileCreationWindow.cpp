#include "ProfileCreationWindow.h"
#include "ui_ProfileCreationWindow.h"

#include <QComboBox>
#include <QDateTimeEdit>
#include <QTextEdit>

static DefConvertTo(int, QSpinBox)
static DefConvertTo(QDate, QDateEdit)

ProfileCreationWindow::
ProfileCreationWindow(QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::ProfileCreationWindow)
{
    ui_->setupUi(this);

    ui_->tableWidget->setColumnCount(2);
    ui_->tableWidget->setRowCount(2);


    profile_ = std::make_unique<IProfile>();
    pf_creationWindow_ = new PFCreationWindow(profile_.get(), this);
}

ProfileCreationWindow::
~ProfileCreationWindow()
{
    delete pf_creationWindow_;
    delete ui_;
}

void
ProfileCreationWindow::
on_pushButton_clicked()
{
    if (pf_creationWindow_->exec()) {
        auto data = CastToint_QSpinBox(*profile_);

        QStringList headers;
        headers << data.getName();
        ui_->tableWidget->setHorizontalHeaderLabels(headers);

        ui_->tableWidget->setCellWidget(0, 0, data.getData(0)->getDataUi(0));
//        ui_->tableWidget->setCellWidget(1, 1, new QTextEdit());
    }
}

void
ProfileCreationWindow::
on_pushButton_2_clicked()
{
    pf_creationWindow_->exec();
}

void
ProfileCreationWindow::
on_buttonBox_accepted()
{
    profile_->setName("p1");
    addStaff(profile_.get());
}
