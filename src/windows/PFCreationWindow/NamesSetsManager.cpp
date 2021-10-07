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
NamesSetsManager()
    : dataTypeComboBox_ (nullptr)
    , recFormatComboBox_(nullptr) {}

NamesSetsManager::
NamesSetsManager(QComboBox* dataTypeComboBox, QComboBox* recFormatComboBox)
    : dataTypeComboBox_ (dataTypeComboBox)
    , recFormatComboBox_(recFormatComboBox) {}

NamesSetsManager::
~NamesSetsManager() {}

void
NamesSetsManager::
setComboBoxes(QComboBox* dataTypeComboBox, QComboBox* recFormatComboBox)
{
    dataTypeComboBox_ = dataTypeComboBox;
    recFormatComboBox_ = recFormatComboBox;
}

QComboBox*
NamesSetsManager::
getDataTypeComboBox() const
{
    return dataTypeComboBox_;
}

QComboBox*
NamesSetsManager::
getRecFormatComboBox() const
{
    return recFormatComboBox_;
}

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
        addDataTypeNameToCB(dataTypeName);
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

    addDataTypeNameToCB(dataTypeName);
    namesSets_.push_back(namesSet);
    return true;
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
    refreshUi();
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
    refreshUi();
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
refreshUi()
{
    if (namesSets_.size() == 0)
        return false;

    if (!dataTypeComboBox_ || !recFormatComboBox_)
        return false;

    QString dataTypeCBCurrentItem = dataTypeComboBox_->currentText();
    QString recFormatCBCurrentItem = recFormatComboBox_->currentText();

    dataTypeComboBox_->clear();
    recFormatComboBox_->clear();

    std::for_each(namesSets_.begin(), namesSets_.end(), [this, &dataTypeCBCurrentItem](const NamesSet& namesSet) {
        dataTypeComboBox_->addItem(namesSet.getDataTypeName());

        if (dataTypeCBCurrentItem == namesSet.getDataTypeName()) {
            size_t recFormatNameCount = namesSet.recFormatNameCount();

            for (size_t i = 0; i < recFormatNameCount; ++i) {
                recFormatComboBox_->addItem(namesSet.getRecFormatName(i));
            }
        }
    });

    dataTypeComboBox_->setCurrentText(std::move(dataTypeCBCurrentItem));
    recFormatComboBox_->setCurrentText(std::move(recFormatCBCurrentItem));
    return true;
}

bool
NamesSetsManager::
switchTo(const QString& dataTypeName)
{
    if (dataTypeName == "")
        return false;

    auto it = getNamesSetIt(dataTypeName);

    if (it == namesSets_.end())
        return false;

    recFormatComboBox_->clear();
    size_t recFormatNameCount = it->recFormatNameCount();

    for (size_t i = 0; i < recFormatNameCount; ++i)
        recFormatComboBox_->addItem(it->getRecFormatName(i));

    return true;
}

QString
NamesSetsManager::
getCurrentSetName() const
{
    return findSetName(dataTypeComboBox_->currentText(), recFormatComboBox_->currentText());
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

bool
NamesSetsManager::
addDataTypeNameToCB(const QString& dataTypeName)
{
    if (dataTypeName == "")
        return false;

    if (!dataTypeComboBox_)
        return false;

    dataTypeComboBox_->addItem(dataTypeName);
    return true;
}
