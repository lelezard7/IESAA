/**
 * QPushButton:pressed { color: #ffffff; }
 *
 * QPushButton:pressed { color: #ffffff; } - rule
 * color: #ffffff;                         - declaration
 * QPushButton:pressed                     - selector
 * color                                   - property
 * value                                   - value
 *
 */

#ifndef STYLESHEETCREATOR_H_
#define STYLESHEETCREATOR_H_

#include <QVector>

#define CreateStylesheetRule(Selector, Declarations)   Selector + Declarations


bool getSelector(const QString& rule, QString& selector, QString* declarations = nullptr);


class StylesheetRuleCreator
{
    using Declarations = QVector<QPair<QString, QString>>;

private:
    QString selector_;
    Declarations declarations_;

public:
    StylesheetRuleCreator(const QString& selector, const QString& property, const QString& value);
    StylesheetRuleCreator() = default;
    virtual ~StylesheetRuleCreator() = default;

    bool setStylesheetRule(const QString& rule);
    QString getStylesheetDeclarations() const;
    QString getStylesheetRule() const;

    bool setSelector(const QString& selector);
    QString getSelector() const;

    bool setDeclaration(const QString& property, const QString& value);
    QPair<QString, QString> getDeclaration(size_t i) const;
    QString getProperty(size_t i) const;
    QString getValue(const QString& property) const;

    bool findProperty(const QString& property) const;
    bool findDeclaration(const QString& property, const QString& value) const;

    void removeDeclaration(const QString& property);
    void clear();

    operator QString() const;

//    operator==

protected:
    Declarations::const_iterator getDeclarationIt(const QString& property) const;
    Declarations::iterator getDeclarationIt(const QString& property);

};


class StyleSheetCreator
{
    QVector<StyleSheetRule> styleSheet_;

public:
    StyleSheetCreator(const QString& selector, const QString& property, const QString& value);
    StyleSheetCreator(const QString& styleSheet);
    StyleSheetCreator();
    virtual ~StyleSheetCreator();

    bool setStyleSheet(const QString& styleSheet);
    QString getStyleSheet() const;

    bool setProperty(const QString& selector, const QString& property, const QString& value);

    bool setRule(const QString& rule);
    QString getRule(const QString& selector) const;
    bool findRule(const QString& selector) const;
    bool removeRule(const QString& selector);

    bool removeProperty(const QString& selector, const QString& property);

    void clear();

    StyleSheetRule getStyleSheetRule();


    bool isTargetCorrect(const QString& target, QString* buffer = nullptr) const;
    bool isPropertyCorrect(const QString& property, QString* buffer = nullptr) const;
    bool isValueCorrect(const QString& value, QString* buffer = nullptr) const;



    operator QString();

protected:
    QVector<StyleSheetRule>::Iterator getStyleSheetIt(const QString& styleSheet);
    QVector<StyleSheetRule>::ConstIterator getStyleSheetCIt(const QString& styleSheet) const;

};

#endif
