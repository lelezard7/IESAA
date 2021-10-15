#include "StyleSheetCreator.h"

#include <regex>


StyleSheetCreator::
StyleSheetCreator() {}

StyleSheetCreator::
~StyleSheetCreator() {}

bool
StyleSheetCreator::
setStyleSheet(const QString& styleSheet)
{

}

QString
StyleSheetCreator::
getStyleSheet() const
{
    QString styleSheet;
    auto itEnd = styleSheet_.end();

    for (auto it = styleSheet_.begin(); it != itEnd; ++it) {
        styleSheet += it->target + "{";

        auto itEnd2 = it->property.end();

        for (auto it2 = it->property.begin(); it2 != itEnd2; ++it2) {
            styleSheet += it2->first + ":" + it2->second + ";";
        }

        styleSheet += "}";
    }

    return styleSheet;
}

bool
StyleSheetCreator::
setProperty(const QString& target, const QString& property, const QString& value)
{
    QString targetBuffer;
    QString propertyBuffer;
    QString valueBuffer;

    if (!isTargetCorrect(target, &targetBuffer) ||
        !isPropertyCorrect(property, &propertyBuffer) ||
        !isValueCorrect(value, &valueBuffer))
        return false;

    auto it = getStyleSheetIt(targetBuffer);

    if (it == styleSheet_.end()) {
        StyleSheetObject styleSheetObject;
        styleSheetObject.target = targetBuffer;
        styleSheetObject.property.push_back(qMakePair(propertyBuffer, valueBuffer));
        styleSheet_.push_back(styleSheetObject);
        return true;
    }

    auto propertyIt = it->findProperty(propertyBuffer);

    if (propertyIt == it->property.end()) {
        it->property.push_back(qMakePair(propertyBuffer, valueBuffer));
        return true;
    }

    propertyIt->second = valueBuffer;
    return true;
}

bool
StyleSheetCreator::
findTarget(const QString& target) const
{
    return getStyleSheetCIt(target) != styleSheet_.cend();
}

bool
StyleSheetCreator::
isTargetCorrect(const QString& target, QString* buffer) const
{
    std::string str = target.toStdString();
    std::regex r(R"(\s*([a-zA-Z]+(::[a-zA-Z]+)?)\s*)");
    std::smatch m;

    bool result = std::regex_match(str, m, r);

    if (result && buffer)
        *buffer = QString::fromStdString(m[1]);

    return result;
}

bool
StyleSheetCreator::
isPropertyCorrect(const QString& property, QString* buffer) const
{
    std::string str = property.toStdString();
    std::regex r(R"(\s*([a-zA-Z-]+)\s*)");
    std::smatch m;

    bool result = std::regex_match(str, m, r);

    if (result && buffer)
        *buffer = QString::fromStdString(m[1]);

    return result;
}

bool
StyleSheetCreator::
isValueCorrect(const QString& value, QString* buffer) const
{
    *buffer = value;
    return true;
}

void
StyleSheetCreator::
clear()
{
    styleSheet_.clear();
}

QVector<StyleSheetCreator::StyleSheetObject>::Iterator
StyleSheetCreator::
getStyleSheetIt(const QString& styleSheet)
{
//    auto propertySearch = [](const QPair<QString, QString> property) {
//        return ;
//    };

    return std::find_if(styleSheet_.begin(), styleSheet_.end(), [&styleSheet](const StyleSheetObject& styleSheetObject) {
        return styleSheet == styleSheetObject.target;
    });
}

QVector<StyleSheetCreator::StyleSheetObject>::ConstIterator
StyleSheetCreator::
getStyleSheetCIt(const QString& styleSheet) const
{
    return std::find_if(styleSheet_.cbegin(), styleSheet_.cend(), [&styleSheet](const StyleSheetObject& styleSheetObject) {
        return styleSheet == styleSheetObject.target;
    });
}



QVector<QPair<QString, QString>>::Iterator
StyleSheetCreator::StyleSheetObject::
findProperty(const QString& propertyName)
{
    return std::find_if(property.begin(), property.end(), [&propertyName](const QPair<QString, QString>& property) {
        return propertyName == property.first;
    });
}
