#include "NamesSetsManager.h"


NamesSet::
NamesSet() {}

NamesSet::
NamesSet(const QString& dataTypeName)
    : dataTypeName_(dataTypeName) {}

NamesSet::
~NamesSet() {}

void
NamesSet::
setDataTypeName(const QString& name)
{
    dataTypeName_ = name;
}

QString
NamesSet::
getDataTypeName() const
{
    return dataTypeName_;
}

bool
NamesSet::
addRecFormatName(const QString& name)
{
    if (findRecFormatName(name))
        return false;

    recFormatNames_.push_back(name);
    return true;
}

QString
NamesSet::
getRecFormatName(size_t i) const
{
    if (i >= static_cast<size_t>(recFormatNames_.size()))
        return "";

    return recFormatNames_[i];
}

void
NamesSet::
removeRecFormatName(const QString& name)
{
    auto it = std::find_if(recFormatNames_.cbegin(), recFormatNames_.cend(), [&name](const QString& recFormatName) {
        return name == recFormatName;
    });

    if (it == recFormatNames_.cend())
        return;

    recFormatNames_.erase(it);
}

size_t
NamesSet::
recFormatNameCount() const
{
    return recFormatNames_.size();
}

bool
NamesSet::
findRecFormatName(const QString& name) const
{
    auto it = std::find_if(recFormatNames_.cbegin(), recFormatNames_.cend(), [&name](const QString& recFormatName) {
        return name == recFormatName;
    });

    return (it != recFormatNames_.cend()) ? true : false;
}



NamesSetsManager::
NamesSetsManager() {}

NamesSetsManager::
~NamesSetsManager() {}

bool
NamesSetsManager::
addNamesSet(const QString& dataTypeName, const QString& recFormatName)
{
    if (dataTypeName == "" || recFormatName == "")
        return false;

    auto it = getNamesSetIt(dataTypeName);

    if (it == namesSets_.end()) {
        NamesSet namesSet(dataTypeName);
        namesSet.addRecFormatName(recFormatName);
        namesSets_.push_back(namesSet);
        return true;
    }

    if (it->findRecFormatName(recFormatName))
        return false;

    it->addRecFormatName(recFormatName);
    return true;
}

bool
NamesSetsManager::
addNamesSet(const NamesSet& namesSet)
{
    QString dataTypeName = namesSet.getDataTypeName();

    if (dataTypeName == "")
        return false;

    auto it = getNamesSetIt(dataTypeName);

    if (it != namesSets_.end())
        return false;

    size_t recFormatNameCount = namesSet.recFormatNameCount();

    if (recFormatNameCount == 0)
        return false;

    for (size_t i = 0; i < recFormatNameCount; ++i) {
        if (namesSet.getRecFormatName(i) == "")
            return false;
    }

    namesSets_.push_back(namesSet);
    return true;
}

void
NamesSetsManager::
removeDataTypeName(const QString& dataTypeName)
{
    if (dataTypeName == "")
        return;

    auto it = std::remove_if(namesSets_.begin(), namesSets_.end(), [&dataTypeName](const NamesSet& namesSet) {
        return dataTypeName == namesSet.getDataTypeName();
    });

    if (it == namesSets_.end())
        return;

    namesSets_.erase(it, namesSets_.end());
}

void
NamesSetsManager::
removeRecFormatName(const QString& dataTypeName, const QString& recFormatName)
{
    if (dataTypeName == "" || recFormatName == "")
        return;

    auto it = getNamesSetIt(dataTypeName);

    if (it == namesSets_.end())
        return;

    if (!it->findRecFormatName(recFormatName))
        return;

    it->removeRecFormatName(recFormatName);
}

std::optional<NamesSet>
NamesSetsManager::
getNamesSet(const QString& dataTypeName) const
{
    if (dataTypeName == "")
        return std::nullopt;

    auto it = getNamesSetIt(dataTypeName);

    if (it == namesSets_.end())
        return std::nullopt;

    return *it;
}

QString
NamesSetsManager::
getDataTypeName(size_t i) const
{
    if (i >= static_cast<size_t>(namesSets_.size()))
        return "";

    return namesSets_[i].getDataTypeName();
}

bool
NamesSetsManager::
findNamesSet(const QString& dataTypeName) const
{
    if (dataTypeName == "")
        return false;

    return getNamesSetIt(dataTypeName) != namesSets_.cend();
}

size_t
NamesSetsManager::
size() const
{
    return namesSets_.size();
}

QString
NamesSetsManager::
findSetName(const QString& dataTypeName, const QString& recFormatName)
{
    if (dataTypeName == "" || recFormatName == "")
        return "";

    return dataTypeName + "_" + recFormatName;
}

QVector<NamesSet>::Iterator
NamesSetsManager::
getNamesSetIt(const QString& dataTypeName)
{
    if (dataTypeName == "")
        return namesSets_.end();

    return std::find_if(namesSets_.begin(), namesSets_.end(), [&dataTypeName](const NamesSet& namesSet) {
        return dataTypeName == namesSet.getDataTypeName();
    });
}

QVector<NamesSet>::ConstIterator
NamesSetsManager::
getNamesSetIt(const QString& dataTypeName) const
{
    if (dataTypeName == "")
        return namesSets_.cend();

    return std::find_if(namesSets_.cbegin(), namesSets_.cend(), [&dataTypeName](const NamesSet& namesSet) {
        return dataTypeName == namesSet.getDataTypeName();
    });
}
