#include "FieldLineEdit.h"


FieldLineEdit::
FieldLineEdit()
    : IFieldWidget()
    , lineEdit_   (new QLineEdit) {}

FieldLineEdit::
FieldLineEdit(QLineEdit* lineEdit)
    : IFieldWidget()
    , lineEdit_   (lineEdit) {}

FieldLineEdit::
~FieldLineEdit()
{
    if (lineEdit_)
        delete lineEdit_;
}

bool
FieldLineEdit::
setWidget(QWidget* widget)
{
    if (!widget)
        return false;

    if (lineEdit_)
        delete lineEdit_;

    lineEdit_ = static_cast<QLineEdit*>(widget);
    return true;
}

QLineEdit*
FieldLineEdit::
getWidget() const
{
    return lineEdit_;
}

bool
FieldLineEdit::
isWidgetSet() const
{
    return lineEdit_ != nullptr;
}

FieldLineEdit*
FieldLineEdit::
copy() const
{
    if (!lineEdit_)
        return nullptr;

    FieldLineEdit* newFieldLineEdit = new FieldLineEdit;
    newFieldLineEdit->lineEdit_ = copyWidget();
    return newFieldLineEdit;
}

QLineEdit*
FieldLineEdit::
copyWidget() const
{
    if (!isWidgetSet())
        return nullptr;

    QLineEdit* lineEdit = getWidget();
    QLineEdit* newLineEdit = new QLineEdit;

    newLineEdit->setText(lineEdit->text());
    newLineEdit->setStyleSheet(lineEdit->styleSheet());
    return newLineEdit;
}

QLineEdit*
FieldLineEdit::
associativeCopyWidget() const
{
    QLineEdit* newLineEdit = copyWidget();
    associateWith(newLineEdit);
    return newLineEdit;
}

bool
FieldLineEdit::
setTextColor(const QColor& color)
{
//    if (!isWidgetSet())
//        return false;

//    QLineEdit* lineEdit = static_cast<QLineEdit*>(getWidget());

//    lineEdit->setStyleSheet("QLineEdit { background-color: yellow }");

    return false;
}

QColor
FieldLineEdit::
getTextColor() const
{
    return QColor();
}

bool
FieldLineEdit::
setBkColor(const QColor& color)
{
    return true;
}

QColor
FieldLineEdit::
getBkColor() const
{
    return QColor();
}

void
FieldLineEdit::
reset()
{
    setWidget(new QLineEdit);
}

bool
FieldLineEdit::
associateWith(QWidget* widget) const
{
    QLineEdit* lineEdit = static_cast<QLineEdit*>(widget);

    connect(lineEdit, &QLineEdit::textChanged, this, &FieldLineEdit::event_textChanged);
    return true;
}

bool
FieldLineEdit::
setText(const QString& text)
{
    if (!lineEdit_)
        return false;

    lineEdit_->setText(text);
    return true;
}

QString
FieldLineEdit::
getText() const
{
    if (!lineEdit_)
        return "";

    return lineEdit_->text();
}

void
FieldLineEdit::
event_textChanged(const QString& text)
{
    lineEdit_->setText(text);
}







//void
//FieldLineEdit::
//textChanged(const QString& text)
//{
////    lineEdit_->
//}
