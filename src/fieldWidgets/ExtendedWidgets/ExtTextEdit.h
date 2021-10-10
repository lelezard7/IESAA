#ifndef EXTTEXTEDIT_H_
#define EXTTEXTEDIT_H_

#include <QTextEdit>


class ExtTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    ExtTextEdit();
    virtual ~ExtTextEdit();

private slots:
    void emitTextChanged();

signals:
    void textChanged(const QString& text);

};

#endif
