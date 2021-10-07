#ifndef NAMESSETSMANAGER_H_
#define NAMESSETSMANAGER_H_

#include <QComboBox>
#include <QString>
#include <QVector>

#include <optional>


class NamesSet
{
    QString dataTypeName_;
    QVector<QString> recFormatNames_;

public:
    NamesSet();
    NamesSet(const QString& dataTypeName);
    virtual ~NamesSet();

    void setDataTypeName(const QString& name);
    QString getDataTypeName() const;

    bool addRecFormatName(const QString& name);
    QString getRecFormatName(size_t i) const;

    void removeRecFormatName(const QString& name);

    size_t recFormatNameCount() const;
    bool findRecFormatName(const QString& name) const;
};


class NamesSetsManager
{
    QVector<NamesSet> namesSets_;

    QComboBox* dataTypeComboBox_;
    QComboBox* recFormatComboBox_;

public:
    NamesSetsManager();
    NamesSetsManager(QComboBox* dataTypeComboBox, QComboBox* recFormatComboBox);
    virtual ~NamesSetsManager();

    void setComboBoxes(QComboBox* dataTypeComboBox, QComboBox* recFormatComboBox);
    QComboBox* getDataTypeComboBox() const;
    QComboBox* getRecFormatComboBox() const;

    bool addNamesSet(const QString& dataTypeName, const QString& recFormatName);
    bool addNamesSet(const NamesSet& namesSet);
    std::optional<NamesSet> getNamesSet(const QString& dataTypeName) const;

    void removeDataTypeName(const QString& dataTypeName);
    void removeRecFormatName(const QString& dataTypeName, const QString& recFormatName);

    QString getDataTypeName(size_t i) const;

    bool refreshUi();
    bool switchTo(const QString& dataTypeName);

    QString getCurrentSetName() const;

    static QString findSetName(const QString& dataTypeName, const QString& recFormatName);

protected:
    QVector<NamesSet>::Iterator getNamesSetIt(const QString& dataTypeName);
    QVector<NamesSet>::ConstIterator getNamesSetIt(const QString& dataTypeName) const;

    bool addDataTypeNameToCB(const QString& dataTypeName);

};


class PFCreationHelper
{
public:

};

#endif
