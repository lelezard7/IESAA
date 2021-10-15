#ifndef STYLESHEETCREATOR_H_
#define STYLESHEETCREATOR_H_

#include <QVector>
#include <QString>


class StyleSheetCreator
{
    struct StyleSheetObject;

private:
    QVector<StyleSheetObject> styleSheet_;

public:
    StyleSheetCreator();
    virtual ~StyleSheetCreator();

    bool setStyleSheet(const QString& styleSheet);
    QString getStyleSheet() const;

    bool setProperty(const QString& target, const QString& property, const QString& value);
    bool findTarget(const QString& target) const;

    bool isTargetCorrect(const QString& target, QString* buffer = nullptr) const;
    bool isPropertyCorrect(const QString& property, QString* buffer = nullptr) const;
    bool isValueCorrect(const QString& value, QString* buffer = nullptr) const;

    void clear();

protected:
    QVector<StyleSheetObject>::Iterator getStyleSheetIt(const QString& styleSheet);
    QVector<StyleSheetObject>::ConstIterator getStyleSheetCIt(const QString& styleSheet) const;

};

struct StyleSheetCreator::StyleSheetObject
{
    QString target;
    QVector<QPair<QString, QString>> property;

    QVector<QPair<QString, QString>>::Iterator findProperty(const QString& propertyName);
};

#endif
