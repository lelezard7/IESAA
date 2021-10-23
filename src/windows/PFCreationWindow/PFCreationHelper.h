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
    AssociativePair<QString, unsigned>* assocs_;

public:
    PFCreationHelper();
    virtual ~PFCreationHelper();

    void setComboBoxes(QComboBox* dataTypeComboBox, QComboBox* recFormatComboBox);
    QComboBox* getDataTypeComboBox() const;
    QComboBox* getRecFormatComboBox() const;

    void setAssocs(AssociativePair<QString, unsigned>* assocs);
    AssociativePair<QString, unsigned>* getAssocs() const;

    void setNamesSetsManager(NamesSetsManager* namesSetsManager);
    NamesSetsManager* getNamesSetsManager() const;

    void setDefaultFieldsCreator(DefaultFieldsCreator* defaultFieldsCreator);
    DefaultFieldsCreator* getDefaultFieldsCreator() const;


    unsigned getWidgetId() const;
    IFieldWidget* copyCurrentFieldWidget() const;

    bool refreshUi();
    bool switchTo(const QString& dataTypeName);

};

#endif
