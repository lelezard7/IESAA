#ifndef FIELDTEXTEDIT_H_
#define FIELDTEXTEDIT_H_

#include "ExtendedWidgets/ExtTextEdit.h"
#include "IFieldWidget.h"


//class FieldTextEdit : public IFieldWidget
//{
//    ExtTextEdit* textEdit_;

//public:
//    FieldTextEdit();
//    FieldTextEdit(ExtTextEdit* textEdit);
//    FieldTextEdit(FieldTextEdit&& other) = delete;
//    FieldTextEdit(const FieldTextEdit& other) = delete;
//    virtual ~FieldTextEdit();


//    virtual bool setWidget(QWidget* widget) override;
//    virtual ExtTextEdit* getWidget() const override;

//    virtual bool isWidgetSet() const override;

//    virtual FieldTextEdit* copy() const override;
//    virtual ExtTextEdit* copyWidget() const override;
//    virtual ExtTextEdit* associativeCopyWidget() const override;

//    virtual bool setTextColor(const QColor& color) override;
//    virtual QColor getTextColor() const override;

//    virtual bool setBkColor(const QColor& color) override;
//    virtual QColor getBkColor() const override;

//    virtual void reset() override;
//    virtual bool associateWith(QWidget* widget) const override;

//    bool setText(const QString& text);
//    QString getText() const;

//protected slots:
//    void event_textChanged(const QString& text);

//};

#endif
