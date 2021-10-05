#include "PFCreationWindow.h"
#include "ui_PFCreationWindow.h"


PFCreationWindow::
PFCreationWindow(QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::PFCreationWindow)
{
    ui_->setupUi(this);
    setFixedSize(size());





//    for (size_t i = 0; i < fieldCreator.size(); ++i) {
//        ui_->comboBox->addItem(fieldCreator.getName(i));
//    }




//    struct FFF
//    {
//        FFF() {};
//        FFF(int f) : A(f) {};
//        int A = 3;
//    };




//    QVector<FFF> gh;
//    gh.push_back(FFF());
//    gh.push_back(FFF(5));
//    gh.push_back(FFF(9));

//    QVector<FFF>::Iterator ddd = gh.begin();
//    ddd++;

//    QVector<FFF>::Iterator ddd2 = ddd;
//    ddd++;

//    int fffffff = ddd->A;


//    QVector<FFF> ppp;
//    ppp.push_back(FFF());
//    ppp.push_back(FFF(5));
//    ppp.push_back(FFF(9));

//    DT_Iterator<FFF, QVector<FFF>> pppt = ppp.begin();
//    pppt++;

//    QVector<FFF>::Iterator pppt2 = pppt;
//    pppt++;

//    int fffffff2 = pppt->A;

//    DT_Iterator<FFF, QVector<FFF>> it(&gh);


//    QVector<std::shared_ptr<FFF>> ff;



//    FIELD_DATA_TYPE(int, QSpinBox) gggg;
//    if (gggg.dataBegin() != gggg.dataEnd())
//        qDebug() << "----------";



//    DT_Iterator<std::shared_ptr<FFF>, QVector<std::shared_ptr<FFF>>> it(&ff);


//    FIELD_DATA_TYPE(int, QSpinBox) gggg;
//    DT_Iterator<int*, QVector<int*>> fdf = gggg.dataBegin();
//    DT_Iterator<QSpinBox*, QVector<QSpinBox*>> fdf2 = gggg.uiDataBegin();
//    (*fdf2)->setValue(**fdf);



//    ui_->comboBox->addItem("Текст");
//    ui_->comboBox->addItem("Логический тип");
//    ui_->comboBox->addItem("Валюта");
//    ui_->comboBox->addItem("Время");
//    ui_->comboBox->addItem("Дата и время");

//    ui_->comboBox_2->addItem("Значение");
//    ui_->comboBox_2->addItem("Лист");
//    ui_->comboBox_2->addItem("Список");
}

PFCreationWindow::
~PFCreationWindow()
{
    delete ui_;
}

void
PFCreationWindow::
on_buttonBox_accepted()
{
//    FIELD_DATA_TYPE(int, QSpinBox)* data = new FIELD_DATA_TYPE(int, QSpinBox);
////    data->refresh();  //TODO: Error
//    data->addData(3);


//    IField<int, QSpinBox>* field = new IField<int, QSpinBox>;
//    field->setName(ui_->lineEdit->text().toStdString());
//    field->addData(data);

//    fieldCreator.addField(ui_->lineEdit->text(),
//                          profile_,
//                          ui_->comboBox->itemText(ui_->comboBox->currentIndex()));
}

