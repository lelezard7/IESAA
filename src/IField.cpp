#include "IField.h"


IFieldWidget::
IFieldWidget(QWidget* widget)
    : widget_(widget) {}

IFieldWidget::
~IFieldWidget()
{
    if (widget_)
        delete widget_;
}

bool
IFieldWidget::
setWidget(QWidget* widget)
{
    if (!widget)
        return false;

    if (widget_)
        delete widget_;

    widget_ = widget;
    return true;
}

QWidget*
IFieldWidget::
getWidget() const
{
    return widget_;
}

bool
IFieldWidget::
isWidgetValid() const
{
    return widget_ != nullptr;
}



FieldLineEdit::
FieldLineEdit()
    : IFieldWidget(new QLineEdit) {}

FieldLineEdit::
FieldLineEdit(QLineEdit* lineEdit)
    : IFieldWidget(lineEdit) {}

FieldLineEdit::
~FieldLineEdit() {}

void
FieldLineEdit::
reset()
{
    setWidget(new QLineEdit);
}

bool
FieldLineEdit::
setTextColor(QColor& color)
{
    if (!isWidgetValid())
        return false;

    QLineEdit* lineEdit = static_cast<QLineEdit*>(getWidget());

    lineEdit->setStyleSheet("QLineEdit { background-color: yellow }");

    return true;
}

bool
FieldLineEdit::
setBkColor(QColor& color)
{
    return true;
}

bool
FieldLineEdit::
drawInTableWidget(QTableWidget& tableWidget, CellCoord cellCoord) const
{
    QLineEdit* lineEdit = copyWidget();

    if (!lineEdit)
        return false;

//    lineEdit->setText("sdfsd");

    tableWidget.setCellWidget(cellCoord.row, cellCoord.column, lineEdit);
    return true;
}

IFieldWidget&
FieldLineEdit::
operator=(const IFieldWidget& other)
{
    QLineEdit* lineEdit = static_cast<QLineEdit*>(getWidget());
    QLineEdit* otherLineEdit = static_cast<QLineEdit*>(other.getWidget());

    lineEdit->setText(otherLineEdit->text());

    return *this;
}

//FieldLineEdit&
//FieldLineEdit::
//operator=(const FieldLineEdit& other)
//{
//    setWidget(other.copyWidget());
//    return *this;
//}

QLineEdit*
FieldLineEdit::
copyWidget() const
{
    if (!isWidgetValid())
        return nullptr;

    QLineEdit* lineEdit = static_cast<QLineEdit*>(getWidget());
    QLineEdit* newLineEdit = new QLineEdit;

    newLineEdit->setText(lineEdit->text());
    newLineEdit->setStyleSheet(lineEdit->styleSheet());

    return newLineEdit;
}







bool
operator==(const FieldLineEdit& lValue, const FieldLineEdit& rValue)
{
    if (!lValue.isWidgetValid() || !rValue.isWidgetValid())
        return false;

    QLineEdit* lLineEdit = static_cast<QLineEdit*>(lValue.getWidget());
    QLineEdit* rLineEdit = static_cast<QLineEdit*>(rValue.getWidget());

    return lLineEdit->text() == rLineEdit->text();
}

bool
operator!=(const FieldLineEdit& lValue, const FieldLineEdit& rValue)
{
    if (!lValue.isWidgetValid() || !rValue.isWidgetValid())
        return false;

    QLineEdit* lLineEdit = static_cast<QLineEdit*>(lValue.getWidget());
    QLineEdit* rLineEdit = static_cast<QLineEdit*>(rValue.getWidget());

    return lLineEdit->text() != rLineEdit->text();
}






//FielTextEdit::
//FielTextEdit()
//    : textEdit_(new QTextEdit)
//{

//}

//FielTextEdit::
//~FielTextEdit()
//{

//}

//void FielTextEdit::setWidget(QWidget* ff)
//{
//    static_assert (std::is_same_v<ff, QTextEdit*>);
//    FielTextEdit::setWidget(static_cast<QTextEdit*>(ff));
//}

//void FielTextEdit::setWidget(QTextEdit* widget)
//{
//    qDebug() << "dddddddddd";

//}

//void
//FielTextEdit::
//setColor(QColor& color)
//{
//    textEdit_->setTextBackgroundColor(color);
//}

//QWidget*
//FielTextEdit::
//getWidget()
//{
//    return textEdit_;
//}



FieldInfo::
FieldInfo()
    : visibility(true) {}

FieldInfo::
~FieldInfo() {}





Field::
Field()
    : widget_(nullptr) {}

Field::
Field(std::string_view name, IFieldWidget* widget, FieldInfo fieldInfo)
    : name_     (name.data())
    , widget_   (widget)
    , fieldInfo_(fieldInfo) {}

Field::
~Field()
{
    if (widget_)
        delete widget_;
}

bool
Field::
setWidget(IFieldWidget* widget)
{
    if (!widget)
        return false;

    if (widget_)
        delete widget_;

    widget_ = widget;
    return true;
}

IFieldWidget*
Field::
getWidget() const
{
    return widget_;
}

void
Field::
setName(std::string_view name)
{
    name_ = name.data();
}

QString
Field::
getName() const
{
    return name_;
}

void
Field::
setFieldInfo(const FieldInfo& fieldInfo)
{
    fieldInfo_ = fieldInfo;
}

FieldInfo
Field::
getFieldInfo() const
{
    return fieldInfo_;
}

FieldInfo&
Field::
fieldInfo()
{
    return fieldInfo_;
}









Profile::
Profile() {}

Profile::
~Profile()
{
    qsizetype fieldsSize = fields_.size();

    for (qsizetype i = 0; i < fieldsSize; ++i)
        delete fields_[i];
}

void
Profile::
setId(ID id)
{
    id_ = id;
}

ID
Profile::
getId() const
{
    return id_;
}

bool
Profile::
addField(Field* field)
{
    if (getField(field->getName()))
        return false;

    fields_.push_back(field);
    return true;
}

Field*
Profile::
getField(QString name) const
{
    auto it = std::find_if(fields_.begin(), fields_.end(), [name](Field* const& field) {
              return name == field->getName();
    });

    if (it == fields_.end())
        return nullptr;

    return *it;
}

Field*
Profile::
getField(size_t i) const
{
    if (i >= static_cast<size_t>(fields_.size()))
        return nullptr;

    return fields_[i];
}

void
Profile::
clear()
{
    qsizetype fieldsSize = fields_.size();

    for (qsizetype i = 0; i < fieldsSize; ++i)
        delete fields_[i];

    fields_.clear();
}

qsizetype
Profile::
fieldsCount() const
{
    return fields_.size();
}
