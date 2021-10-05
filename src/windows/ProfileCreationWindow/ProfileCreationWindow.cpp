#include "ProfileCreationWindow.h"
#include "ui_ProfileCreationWindow.h"

#include "../../LocalDB.h"

#include <QComboBox>

























//static DefConvertTo(int, QSpinBox)
//static DefConvertTo(QDate, QDateEdit)


ProfileCreationWindow::
ProfileCreationWindow(FieldDataBase* defaultDB, QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::ProfileCreationWindow)
{
    ui_->setupUi(this);

    fieldCreator_.setTableWidget(ui_->tableWidget);
    fieldCreator_.setFieldDataBase(defaultDB);
    fieldCreator_.addColumn("Видимость");
    fieldCreator_.addColumn("Название");
    fieldCreator_.addColumn("Значение");




    ui_->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);

//    ui_->tableWidget->setColumnCount(2);
    ui_->tableWidget->setRowCount(4);





    QColor color(70, 70, 70);
    CellCoord cellCoord;
    cellCoord.row = 1;
    cellCoord.column = 1;

    FieldLineEdit* fieldWidget = new FieldLineEdit;
    fieldWidget->setTextColor(color);

    fieldWidget->drawInTableWidget(*ui_->tableWidget, cellCoord);

    ProfileDataBase pdb;
    pdb.get(1);


//    fieldCreator_.refresh();

//    ui_->tableWidget->setCellWidget(cellCoord.row, cellCoord.column, new QLineEdit("dfg"));



//    QTableWidgetItem* fd = new QTableWidgetItem;
//    fd->setBackground(QColor(50, 59, 50));
//    fd->setText("sadffdgdf");
//    ui_->tableWidget->setItem(1, 1, fd);

//    ui_->tableWidget->item(1, 1)->setBackground(QColor(70, 70, 70));

//    IFielWidget* fw = new IFielTextEdit;
//    QColor dff(70, 70, 70);
//    fw->setColor(dff);

//    QDateTimeEdit* fddd = new QDateTimeEdit;
//    fw->setWidget(fddd);


////    QTextEdit* te = new QTextEdit;

////    te->setTextColor(QColor(200, 200, 200));
////    te->setTextBackgroundColor(QColor(70, 70, 70));
////    te->setText("sdfsdf\nsdfsdf");
//    ui_->tableWidget->setCellWidget(1, 1, fw->getWidget());

//    QColor dff2(140, 140, 140);
//    fw->setColor(dff2);


//    ui_->tableWidget->set


//    profile_ = std::make_unique<IProfile>();
//    pf_creationWindow_ = new PFCreationWindow(profile_.get(), this);
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
//    if (pf_creationWindow_->exec()) {
//        for (size_t i = 0; i < profile_->size(); ++i) {
//            switch (profile_->getFieldTypeId(i)) {
//                case DATATYPE_ID(int, QSpinBox): {
//                    auto data = CastToint_QSpinBox(*profile_.get());
//                    profile_->getField<int, QSpinBox>("");
//                    QStringList headers;
//                    headers << data.getName();
//                    ui_->tableWidget->setHorizontalHeaderLabels(headers);

//                    ui_->tableWidget->setCellWidget(0, 0, *(*data.dataBegin())->uiDataBegin());
//                    break;
//                }

//                case DATATYPE_ID(QDate, QDateEdit): {
//                    auto data = CastToQDate_QDateEdit(*profile_.get());
//                    QStringList headers;
//                    headers << data.getName();
//                    ui_->tableWidget->setHorizontalHeaderLabels(headers);

//                    ui_->tableWidget->setCellWidget(0, 1, *(*data.dataBegin())->uiDataBegin());
//                    break;
//                }
//            }
//        }
//    }


}

void
ProfileCreationWindow::
on_pushButton_2_clicked()
{
//    pf_creationWindow_->exec();
}

void
ProfileCreationWindow::
on_buttonBox_accepted()
{
//    profile_->setName("p1");
//    addStaff(profile_.get());
}
