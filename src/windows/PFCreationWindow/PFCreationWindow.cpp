#include "PFCreationWindow.h"
#include "ui_PFCreationWindow.h"

















FieldCreator::
FieldCreator() {}

FieldCreator::
FieldCreator(QComboBox* comboBox)
    : comboBox_(comboBox) {}

FieldCreator::
~FieldCreator()
{
    qsizetype assocSize = assoc_.size();

    for (qsizetype i = 0; i < assocSize; ++i)
        delete assoc_[i].second;

    assoc_.clear();
}

void
FieldCreator::
setComboBox(QComboBox* comboBox)
{
    comboBox_ = comboBox;
}

bool
FieldCreator::
createAssociation(QString name, IFieldWidget* widget)
{
    if (!comboBox_)
        return false;

//    comboBox_->addItem(name);

    auto it = std::find_if(assoc_.cbegin(), assoc_.cend(), [name](const std::pair<QString, IFieldWidget*>& pair) {
        return name == pair.first;
    });

    if (it != assoc_.cend())
        return false;

    assoc_.push_back(std::make_pair(name, widget));
    return true;
}

IFieldWidget*
FieldCreator::
getWidget(QString name)
{
    auto it = std::find_if(assoc_.cbegin(), assoc_.cend(), [name](const std::pair<QString, IFieldWidget*>& pair) {
        return name == pair.first;
    });

    if (it == assoc_.cend())
        return nullptr;



    IFieldWidget* newWidget = new FieldLineEdit;
    *newWidget = *it->second;

    return newWidget;
}

IFieldWidget*
FieldCreator::
widget(QString name)
{
    auto it = std::find_if(assoc_.cbegin(), assoc_.cend(), [name](const std::pair<QString, IFieldWidget*>& pair) {
        return name == pair.first;
    });

    if (it == assoc_.cend())
        return nullptr;

    return it->second;
}



















PFCreationWindow::
PFCreationWindow(TableManager_Profile* fieldCreator, QWidget* parent)
    : QDialog(parent)
    , ui_(new Ui::PFCreationWindow)
    , fieldCreator_(fieldCreator)
{
    ui_->setupUi(this);
    setFixedSize(size());

    fieldAssoc_.setComboBox(ui_->comboBox);
    namesSetsManager_.setComboBoxes(ui_->comboBox, ui_->comboBox_2);


    QLineEdit* le = new QLineEdit("ffffffffff");
    IFieldWidget* widget = new FieldLineEdit;
    widget->setWidget(le);


    namesSetsManager_.addNamesSet("Текст",          "Значение");
    namesSetsManager_.addNamesSet("Текст",          "Лист");
    namesSetsManager_.addNamesSet("Число",          "Значение");
    namesSetsManager_.addNamesSet("Логический тип", "Значение");
    namesSetsManager_.addNamesSet("Валюта",         "Значение");
    namesSetsManager_.addNamesSet("Время",          "Значение");
    namesSetsManager_.addNamesSet("Дата",           "Значение");
    namesSetsManager_.addNamesSet("Дата и время",   "Значение");

    fieldAssoc_.createAssociation(NamesSetsManager::findSetName("Текст", "Значение"), widget);
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
//    static_cast<QLineEdit*>(fieldAssoc_.widget(fff)->getWidget())->setText(ui_->lineEdit->text());
    Field* field = new Field;

    IFieldWidget* fieldWidget = fieldAssoc_.getWidget(namesSetsManager_.getCurrentSetName());
    if (!fieldWidget) {
        delete field;
        delete fieldWidget;
        return;
    }

    field->setWidget(fieldWidget);

    fieldCreator_->addField(field);
}



void PFCreationWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    namesSetsManager_.switchTo(arg1);
}

