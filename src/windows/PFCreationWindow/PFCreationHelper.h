#ifndef PFCREATIONHELPER_H_
#define PFCREATIONHELPER_H_

#include "DefaultFieldsCreator.h"
#include "NamesSetsManager.h"


class PFCreationHelper
{
    QComboBox* dataTypeComboBox_;
    QComboBox* recFormatComboBox_;

    DefaultFieldsCreator* defaultFieldsCreator_;
    NamesSetsManager* namesSetsManager_;

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
