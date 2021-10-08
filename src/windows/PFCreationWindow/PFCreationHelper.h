#ifndef PFCREATIONHELPER_H_
#define PFCREATIONHELPER_H_

#include "NamesSetsManager.h"
#include "DefaultFieldsCreator.h"


class PFCreationHelper
{
    DefaultFieldsCreator* defaultFieldsCreator_;
    NamesSetsManager* namesSetsManager_;

    QComboBox* dataTypeComboBox_;
    QComboBox* recFormatComboBox_;

public:
    PFCreationHelper();
    virtual ~PFCreationHelper();

    void setComboBoxes(QComboBox* dataTypeComboBox, QComboBox* recFormatComboBox);
    QComboBox* getDataTypeComboBox() const;
    QComboBox* getRecFormatComboBox() const;

    void setNamesSetsManager(NamesSetsManager* namesSetsManager);
    NamesSetsManager* getNamesSetsManager() const;

    void setDefaultFieldsCreator(DefaultFieldsCreator* defaultFieldsCreator);
    DefaultFieldsCreator* getDefaultFieldsCreator() const;

    QString getCurrentSetName() const;
    IFieldWidget* copyCurrentFieldWidget() const;

    bool refreshUi();
    bool switchTo(const QString& dataTypeName);

};

#endif
