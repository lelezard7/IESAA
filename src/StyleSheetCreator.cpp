#include "StyleSheetCreator.h"

#include <regex>


bool
getSelector(const QString& rule, QString& selector, QString* declarations)
{
    if (rule == "")
        return false;

    std::string rule_str = rule.toStdString();
    std::regex r(R"(\s*(.*)\s*({.*})\s*)");
    std::smatch m;

    if (!std::regex_match(rule_str, m, r))
        return false;

    selector = QString::fromStdString(m[1]);

    if (declarations)
        *declarations = QString::fromStdString(m[2]);

    return true;
}



StylesheetRuleCreator::
StylesheetRuleCreator(const QString& selector, const QString& property, const QString& value)
    : selector_(selector)
{
    if (property != "" && value != "")
        declarations_.push_back(qMakePair(property, value));
}

bool
StylesheetRuleCreator::
setStylesheetRule(const QString& rule)
{
    if (rule == "")
        return false;

    QString selector;
    Declarations declarations;

    QString buffer;
    if (!::getSelector(rule, selector, &buffer))
        return false;

    //Удаляем { и }.
    buffer.remove(0, 1);
    buffer.remove(buffer.size() - 1, 1);

    std::string declarations_str = buffer.toStdString();
    std::regex r(R"(\s*(.+)\s*:\s*(.+)\s*;\s*)");
    std::smatch m;

    std::sregex_iterator(declarations_str.begin(), declarations_str.end(), r);

    if (!)
        return false;

    declarations_str = QString::fromStdString(m[1]);

    return result;
}

QString
StylesheetRuleCreator::
getStylesheetDeclarations() const
{
    if (declarations_.size() == 0)
        return "";

    QString stylesheetDeclarations = "{";
    auto itEnd = declarations_.cend();

    for (auto it = declarations_.cbegin(); it != itEnd; ++it) {
        stylesheetDeclarations += it->first + ":" + it->second + ";";
    }

    stylesheetDeclarations += "}";
    return stylesheetDeclarations;
}

QString
StylesheetRuleCreator::
getStylesheetRule() const
{
    if (selector_ == "" || declarations_.size() == 0)
        return "";

    return CreateStylesheetRule(selector_, getStylesheetDeclarations());
}

bool
StylesheetRuleCreator::
setSelector(const QString& selector)
{ selector_ = selector; }

QString
StylesheetRuleCreator::
getSelector() const
{ return selector_; }

bool
StylesheetRuleCreator::
setDeclaration(const QString& property, const QString& value)
{
    if (property == "" || value == "")
        return false;

    auto it = getDeclarationIt(property);

    if (it != declarations_.end()) {
        it->second = value;
        return true;
    }

    declarations_.push_back(qMakePair(property, value));
    return true;
}

QPair<QString, QString>
StylesheetRuleCreator::
getDeclaration(size_t i) const
{
    if (i >= static_cast<size_t>(declarations_.size()))
        return QPair<QString, QString>();

    return declarations_[i];
}

QString
StylesheetRuleCreator::
getProperty(size_t i) const
{
    if (i >= static_cast<size_t>(declarations_.size()))
        return "";

    return declarations_[i].first;
}

QString
StylesheetRuleCreator::
getValue(const QString& property) const
{
    if (property == "")
        return "";

    auto it = getDeclarationIt(property);

    if (it == declarations_.cend())
        return "";

    return it->second;
}

bool
StylesheetRuleCreator::
findProperty(const QString& property) const
{
    if (property == "")
        return false;

    return getDeclarationIt(property) != declarations_.cend();
}

bool
StylesheetRuleCreator::
findDeclaration(const QString& property, const QString& value) const
{
    if (property == "" || value == "")
        return false;

    auto it = getDeclarationIt(property);

    if (it == declarations_.cend())
        return false;

    return it->second == value;
}

void
StylesheetRuleCreator::
removeDeclaration(const QString& property)
{
    if (property == "")
        return;

    auto it = getDeclarationIt(property);

    if (it == declarations_.end())
        return;

    declarations_.erase(it);
}

void
StylesheetRuleCreator::
clear()
{
    selector_.clear();
    declarations_.clear();
}

StylesheetRuleCreator::Declarations::const_iterator
StylesheetRuleCreator::
getDeclarationIt(const QString& property) const
{
    return std::find_if(declarations_.cbegin(), declarations_.cend(), [&property](const QPair<QString, QString>& declaration) {
        return property == declaration.first;
    });
}

StylesheetRuleCreator::Declarations::iterator
StylesheetRuleCreator::
getDeclarationIt(const QString& property)
{
    return std::find_if(declarations_.begin(), declarations_.end(), [&property](const QPair<QString, QString>& declaration) {
        return property == declaration.first;
    });
}

























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
        styleSheet += it->selector + "{";

        auto itEnd2 = it->declaration.end();

        for (auto it2 = it->declaration.begin(); it2 != itEnd2; ++it2) {
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
        StyleSheetRule styleSheetObject;
        styleSheetObject.selector = targetBuffer;
        styleSheetObject.declaration.push_back(qMakePair(propertyBuffer, valueBuffer));
        styleSheet_.push_back(styleSheetObject);
        return true;
    }

    auto propertyIt = it->findProperty(propertyBuffer);

    if (propertyIt == it->declaration.end()) {
        it->declaration.push_back(qMakePair(propertyBuffer, valueBuffer));
        return true;
    }

    propertyIt->second = valueBuffer;
    return true;
}

bool
StyleSheetCreator::
findRule(const QString& target) const
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

QVector<StyleSheetCreator::StyleSheetRule>::Iterator
StyleSheetCreator::
getStyleSheetIt(const QString& styleSheet)
{
//    auto propertySearch = [](const QPair<QString, QString> property) {
//        return ;
//    };

    return std::find_if(styleSheet_.begin(), styleSheet_.end(), [&styleSheet](const StyleSheetRule& styleSheetObject) {
        return styleSheet == styleSheetObject.selector;
    });
}

QVector<StyleSheetCreator::StyleSheetRule>::ConstIterator
StyleSheetCreator::
getStyleSheetCIt(const QString& styleSheet) const
{
    return std::find_if(styleSheet_.cbegin(), styleSheet_.cend(), [&styleSheet](const StyleSheetRule& styleSheetObject) {
        return styleSheet == styleSheetObject.selector;
    });
}



QVector<QPair<QString, QString>>::Iterator
StyleSheetCreator::StyleSheetRule::
findProperty(const QString& propertyName)
{
    return std::find_if(declaration.begin(), declaration.end(), [&propertyName](const QPair<QString, QString>& property) {
        return propertyName == property.first;
    });
}
