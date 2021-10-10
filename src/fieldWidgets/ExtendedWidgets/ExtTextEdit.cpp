#include "ExtTextEdit.h"

#include <QtGlobal>


ExtTextEdit::
ExtTextEdit()
    : QTextEdit()
{
    connect(this, &QTextEdit::textChanged, this, &ExtTextEdit::emitTextChanged);
}

ExtTextEdit::
~ExtTextEdit() {}

void
ExtTextEdit::
emitTextChanged()
{
    emit textChanged(toPlainText());
}
