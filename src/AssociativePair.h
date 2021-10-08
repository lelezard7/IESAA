#ifndef ASSOCIATIVEPAIR_H_
#define ASSOCIATIVEPAIR_H_

#include <QVector>
#include <QString>

#include <optional>


template <class T1, class T2>
class AssociativePair
{
    using AssocPair = std::pair<T1, T2>;
    using AssocPairsIt = typename QVector<std::pair<T1, T2>>::Iterator;
    using AssocPairsCIt = typename QVector<std::pair<T1, T2>>::ConstIterator;

protected:
    QVector<AssocPair> associativePairs_;

public:
    AssociativePair();
    virtual ~AssociativePair();

    virtual bool createAssociation(T1 name, T2 value);
    virtual bool deleteAssociation(T1 name);

    virtual std::optional<T2> getValue(T1 name) const;
    virtual std::optional<T1> getName(size_t i) const;

    virtual void clear();

    virtual bool find(T1 name) const;
    virtual size_t size() const;

protected:
    virtual AssocPairsIt getAssociativePairsIt(T1 name);
    virtual AssocPairsCIt getAssociativePairsIt(T1 name) const;

    virtual bool isNameCorrect(T1 name) const;
    virtual bool isValueCorrect(T2 value) const;

};


template <class T>
class AssociativePair<QString, T*>
{
    using AssocPair = std::pair<QString, T*>;
    using AssocPairsIt = typename QVector<std::pair<QString, T*>>::Iterator;
    using AssocPairsCIt = typename QVector<std::pair<QString, T*>>::ConstIterator;

protected:
    QVector<AssocPair> associativePairs_;

public:
    AssociativePair();
    virtual ~AssociativePair();

    virtual bool createAssociation(const QString& name, T* value);
    virtual bool deleteAssociation(const QString& name);

    virtual T* getValue(const QString& name) const;
    virtual QString getName(size_t i) const;

    virtual void clear();

    virtual bool find(const QString& name) const;
    virtual size_t size() const;

protected:
    virtual AssocPairsIt getAssociativePairsIt(const QString& name);
    virtual AssocPairsCIt getAssociativePairsIt(const QString& name) const;

    virtual bool isNameCorrect(const QString& name) const;
    virtual bool isValueCorrect(T* value) const;
};

#include "AssociativePair.inl"

#include "LocalDB.h"
#include "IProfile.h"

typedef AssociativePair<QString, FieldDataBase*> DefaultFieldDataBase;
typedef AssociativePair<QString, ProfileDataBase*> ProfileDataBaseManager;


#endif
