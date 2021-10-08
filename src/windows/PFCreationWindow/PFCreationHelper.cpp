#include "PFCreationHelper.h"


PFCreationHelper::
PFCreationHelper()
    : defaultFieldsCreator_(nullptr)
    , namesSetsManager_    (nullptr)
    , dataTypeComboBox_    (nullptr)
    , recFormatComboBox_   (nullptr) {}

PFCreationHelper::
~PFCreationHelper() {}

void
PFCreationHelper::
setComboBoxes(QComboBox* dataTypeComboBox, QComboBox* recFormatComboBox)
{
    dataTypeComboBox_ = dataTypeComboBox;
    recFormatComboBox_ = recFormatComboBox;
}

QComboBox*
PFCreationHelper::
getDataTypeComboBox() const
{
    return dataTypeComboBox_;
}

QComboBox*
PFCreationHelper::
getRecFormatComboBox() const
{
    return recFormatComboBox_;
}

void
PFCreationHelper::
setNamesSetsManager(NamesSetsManager* namesSetsManager)
{
    namesSetsManager_ = namesSetsManager;
}

NamesSetsManager*
PFCreationHelper::
getNamesSetsManager() const
{
    return namesSetsManager_;
}

void
PFCreationHelper::
setDefaultFieldsCreator(DefaultFieldsCreator* defaultFieldsCreator)
{
    defaultFieldsCreator_ = defaultFieldsCreator;
}

DefaultFieldsCreator*
PFCreationHelper::
getDefaultFieldsCreator() const
{
    return defaultFieldsCreator_;
}

QString
PFCreationHelper::
getCurrentSetName() const
{
    if (!namesSetsManager_ || !dataTypeComboBox_ || !recFormatComboBox_)
        return "";

    return NamesSetsManager::findSetName(dataTypeComboBox_->currentText(), recFormatComboBox_->currentText());
}

IFieldWidget*
PFCreationHelper::
copyCurrentFieldWidget() const
{
    if (!defaultFieldsCreator_)
        return nullptr;

    return defaultFieldsCreator_->copyValue(getCurrentSetName());
}

bool
PFCreationHelper::
refreshUi()
{
    if (!namesSetsManager_ || !dataTypeComboBox_ || !recFormatComboBox_)
        return false;

    if (namesSetsManager_->size() == 0)
        return false;

    QString dataTypeCBCurrentItem = dataTypeComboBox_->currentText();
    QString recFormatCBCurrentItem = recFormatComboBox_->currentText();

    dataTypeComboBox_->clear();
    recFormatComboBox_->clear();

    size_t namesSetsManagerSize = namesSetsManager_->size();
    QString dataTypeName;

    for (size_t i = 0; i < namesSetsManagerSize; ++i) {
        dataTypeName = namesSetsManager_->getDataTypeName(i);
        dataTypeComboBox_->addItem(dataTypeName);

        if (dataTypeCBCurrentItem == dataTypeName) {
            NamesSet namesSet = *namesSetsManager_->getNamesSet(dataTypeName);
            size_t namesSetSize = namesSet.recFormatNameCount();

            for (size_t i = 0; i < namesSetSize; ++i) {
                recFormatComboBox_->addItem(namesSet.getRecFormatName(i));
            }
        }
    }

    dataTypeComboBox_->setCurrentText(std::move(dataTypeCBCurrentItem));
    recFormatComboBox_->setCurrentText(std::move(recFormatCBCurrentItem));
    return true;
}

bool
PFCreationHelper::
switchTo(const QString& dataTypeName)
{
    if (!namesSetsManager_ || !recFormatComboBox_)
        return false;

    if (dataTypeName == "")
        return false;

    auto namesSetOpt = namesSetsManager_->getNamesSet(dataTypeName);

    if (!namesSetOpt.has_value())
        return false;

    recFormatComboBox_->clear();
    size_t recFormatNameCount = namesSetOpt->recFormatNameCount();

    for (size_t i = 0; i < recFormatNameCount; ++i)
        recFormatComboBox_->addItem(namesSetOpt->getRecFormatName(i));

    return true;
}
