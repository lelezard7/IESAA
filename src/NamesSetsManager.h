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

public:
    NamesSetsManager();
    virtual ~NamesSetsManager();

    bool addNamesSet(const QString& dataTypeName, const QString& recFormatName);
    bool addNamesSet(const NamesSet& namesSet);

    void removeDataTypeName(const QString& dataTypeName);
    void removeRecFormatName(const QString& dataTypeName, const QString& recFormatName);

    std::optional<NamesSet> getNamesSet(const QString& dataTypeName) const;
    QString getDataTypeName(size_t i) const;

    bool findNamesSet(const QString& dataTypeName) const;
    size_t size() const;

    static QString findSetName(const QString& dataTypeName, const QString& recFormatName);

protected:
    QVector<NamesSet>::Iterator getNamesSetIt(const QString& dataTypeName);
    QVector<NamesSet>::ConstIterator getNamesSetIt(const QString& dataTypeName) const;

};

#endif
