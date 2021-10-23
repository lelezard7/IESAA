#include "FieldTextEdit.h"


//FieldTextEdit::
//FieldTextEdit()
//    : IFieldWidget()
//    , textEdit_   (new ExtTextEdit) {}

//FieldTextEdit::
//FieldTextEdit(ExtTextEdit* textEdit)
//    : IFieldWidget()
//    , textEdit_   (textEdit) {}

//FieldTextEdit::
//~FieldTextEdit()
//{
//    if (textEdit_)
//        delete textEdit_;
//}

//bool
//FieldTextEdit::
//setWidget(QWidget* widget)
//{
//    if (!widget)
//        return false;

//    if (textEdit_)
//        delete textEdit_;

//    textEdit_ = reinterpret_cast<ExtTextEdit*>(widget);
//    return true;
//}

//ExtTextEdit*
//FieldTextEdit::
//getWidget() const
//{
//    return textEdit_;
//}

//bool
//FieldTextEdit::
//isWidgetSet() const
//{
//    return textEdit_ != nullptr;
//}

//FieldTextEdit*
//FieldTextEdit::
//copy() const
//{
//    if (!textEdit_)
//        return nullptr;

//    FieldTextEdit* newFieldTextEdit = new FieldTextEdit;
//    newFieldTextEdit->textEdit_ = copyWidget();
//    return newFieldTextEdit;
//}

//ExtTextEdit*
//FieldTextEdit::
//copyWidget() const
//{
//    if (!textEdit_)
//        return nullptr;

//    ExtTextEdit* textEdit = getWidget();
//    ExtTextEdit* newTextEdit = new ExtTextEdit;

//    newTextEdit->setText(textEdit->toPlainText());
//    newTextEdit->setStyleSheet(textEdit->styleSheet());
//    return newTextEdit;
//}

//ExtTextEdit*
//FieldTextEdit::
//associativeCopyWidget() const
//{
//    ExtTextEdit* newTextEdit = copyWidget();
//    associateWith(newTextEdit);
//    return newTextEdit;
//}

//bool
//FieldTextEdit::
//setTextColor(const QColor& color)
//{
//    return false;
//}

//QColor
//FieldTextEdit::
//getTextColor() const
//{
//    return QColor();
//}

//bool
//FieldTextEdit::
//setBkColor(const QColor& color)
//{
//    return false;
//}

//QColor
//FieldTextEdit::
//getBkColor() const
//{
//    return QColor();
//}

//void
//FieldTextEdit::
//reset()
//{
//    setWidget(new ExtTextEdit);
//}

//bool
//FieldTextEdit::
//associateWith(QWidget* widget) const
//{
//    ExtTextEdit* textEdit = static_cast<ExtTextEdit*>(widget);

//    connect(textEdit, qOverload<const QString&>(&ExtTextEdit::textChanged), this, &FieldTextEdit::event_textChanged);
//    return true;
//}

//bool
//FieldTextEdit::
//setText(const QString& text)
//{
//    if (!textEdit_)
//        return false;

//    textEdit_->setText(text);
//    return true;
//}

//QString
//FieldTextEdit::
//getText() const
//{
//    return textEdit_->toPlainText();
//}

//void
//FieldTextEdit::
//event_textChanged(const QString& text)
//{
//    textEdit_->setText(text);
//}
