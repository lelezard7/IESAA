#include "AssociativePair.h"


template <class T1, class T2>
AssociativePair<T1, T2>::
AssociativePair() {}

template<class T1, class T2>
AssociativePair<T1, T2>::
~AssociativePair()
{
    associativePairs_.clear();
}

template<class T1, class T2>
bool
AssociativePair<T1, T2>::
createAssociation(T1 name, T2 value)
{
    if (!isNameCorrect(name) || !isValueCorrect(value))
        return false;

    if (getAssociativePairsIt(name) != associativePairs_.end())
        return false;

    associativePairs_.push_back(std::make_pair(name, value));
    return true;
}

template<class T1, class T2>
bool
AssociativePair<T1, T2>::
deleteAssociation(T1 name)
{
    if (!isNameCorrect(name))
        return false;

    auto it = getAssociativePairsIt(name);

    if (it == associativePairs_.end())
        return false;

    associativePairs_.erase(it);
    return true;
}

template<class T1, class T2>
std::optional<T2>
AssociativePair<T1, T2>::
getValue(T1 name) const
{
    if (!isNameCorrect(name))
        return std::nullopt;

    auto it = getAssociativePairsIt(name);

    if (it == associativePairs_.cend())
        return std::nullopt;

    return it->second;
}

template<class T1, class T2>
std::optional<T1>
AssociativePair<T1, T2>::
getName(size_t i) const
{
    if (i >= static_cast<size_t>(associativePairs_.size()))
        return std::nullopt;

    return associativePairs_[i].first;
}

template<class T1, class T2>
void
AssociativePair<T1, T2>::
clear()
{
    associativePairs_.clear();
}

template<class T1, class T2>
bool
AssociativePair<T1, T2>::
find(T1 name) const
{
    if (!isNameCorrect(name))
        return false;

    return getAssociativePairsIt(name) != associativePairs_.cend();
}

template<class T1, class T2>
size_t
AssociativePair<T1, T2>::
size() const
{
    return associativePairs_.size();
}

template<class T1, class T2>
typename AssociativePair<T1, T2>::AssocPairsIt
AssociativePair<T1, T2>::
getAssociativePairsIt(T1 name)
{
    if (!isNameCorrect(name))
        return associativePairs_.end();

    return std::find_if(associativePairs_.begin(), associativePairs_.end(),
                        [name](const std::pair<T1, T2>& assocPair) {
        return name == assocPair.first;
    });
}

template<class T1, class T2>
typename AssociativePair<T1, T2>::AssocPairsCIt
AssociativePair<T1, T2>::
getAssociativePairsIt(T1 name) const
{
    if (!isNameCorrect(name))
        return associativePairs_.cend();

    return std::find_if(associativePairs_.cbegin(), associativePairs_.cend(),
                        [name](const std::pair<T1, T2>& assocPair) {
        return name == assocPair.first;
    });
}

template<class T1, class T2>
bool
AssociativePair<T1, T2>::
isNameCorrect(T1) const
{
    return true;
}

template<class T1, class T2>
bool
AssociativePair<T1, T2>::
isValueCorrect(T2) const
{
    return true;
}



template <class T1, class T2>
AssociativePair<T1, T2*>::
AssociativePair() {}

template <class T1, class T2>
AssociativePair<T1, T2*>::
~AssociativePair()
{
    qsizetype associativePairsSize = associativePairs_.size();

    for (qsizetype i = 0; i < associativePairsSize; ++i)
        delete associativePairs_[i].second;

    associativePairs_.clear();
}

template <class T1, class T2>
bool
AssociativePair<T1, T2*>::
createAssociation(T1 name, T2* value)
{
    if (!isNameCorrect(name) || !isValueCorrect(value))
        return false;

    if (getAssociativePairsIt(name) != associativePairs_.end())
        return false;

    associativePairs_.push_back(std::make_pair(name, value));
    return true;
}

template <class T1, class T2>
bool
AssociativePair<T1, T2*>::
deleteAssociation(T1 name)
{
    if (!isNameCorrect(name))
        return false;

    auto it = getAssociativePairsIt(name);

    if (it == associativePairs_.end())
        return false;

    delete it->second;
    associativePairs_.erase(it);
    return true;
}

template <class T1, class T2>
T2*
AssociativePair<T1, T2*>::
getValue(T1 name) const
{
    if (!isNameCorrect(name))
        return nullptr;

    auto it = getAssociativePairsIt(name);

    if (it == associativePairs_.cend())
        return nullptr;

    return it->second;
}

template <class T1, class T2>
T1
AssociativePair<T1, T2*>::
getName(size_t i) const
{
    if (i >= static_cast<size_t>(associativePairs_.size()))
        return FLAG_NULL;

    return associativePairs_[i].first;
}

template <class T1, class T2>
void
AssociativePair<T1, T2*>::
clear()
{
    qsizetype associativePairsSize = associativePairs_.size();

    for (qsizetype i = 0; i < associativePairsSize; ++i)
        delete associativePairs_[i].second;

    associativePairs_.clear();
}

template <class T1, class T2>
bool
AssociativePair<T1, T2*>::
find(T1 name) const
{
    if (!isNameCorrect(name))
        return false;

    return getAssociativePairsIt(name) != associativePairs_.cend();
}

template <class T1, class T2>
size_t
AssociativePair<T1, T2*>::
size() const
{
    return associativePairs_.size();
}

template <class T1, class T2>
typename AssociativePair<T1, T2*>::AssocPairsIt
AssociativePair<T1, T2*>::
getAssociativePairsIt(T1 name)
{
    if (!isNameCorrect(name))
        return associativePairs_.end();

    return std::find_if(associativePairs_.begin(), associativePairs_.end(),
                        [&name](const std::pair<T1, T2*>& assocPair) {
        return name == assocPair.first;
    });
}

template <class T1, class T2>
typename AssociativePair<T1, T2*>::AssocPairsCIt
AssociativePair<T1, T2*>::
getAssociativePairsIt(T1 name) const
{
    if (!isNameCorrect(name))
        return associativePairs_.cend();

    return std::find_if(associativePairs_.cbegin(), associativePairs_.cend(),
                        [&name](const std::pair<T1, T2*>& assocPair) {
        return name == assocPair.first;
    });
}

template <class T1, class T2>
bool
AssociativePair<T1, T2*>::
isNameCorrect(T1 name) const
{
    return name != FLAG_NULL;
}

template <class T1, class T2>
bool
AssociativePair<T1, T2*>::
isValueCorrect(T2* value) const
{
    return value != nullptr;
}



template <class T>
AssociativePair<QString, T*>::
AssociativePair() {}

template <class T>
AssociativePair<QString, T*>::
~AssociativePair()
{
    qsizetype associativePairsSize = associativePairs_.size();

    for (qsizetype i = 0; i < associativePairsSize; ++i)
        delete associativePairs_[i].second;

    associativePairs_.clear();
}

template <class T>
bool
AssociativePair<QString, T*>::
createAssociation(const QString& name, T* value)
{
    if (!isNameCorrect(name) || !isValueCorrect(value))
        return false;

    if (getAssociativePairsIt(name) != associativePairs_.end())
        return false;

    associativePairs_.push_back(std::make_pair(name, value));
    return true;
}

template <class T>
bool
AssociativePair<QString, T*>::
deleteAssociation(const QString& name)
{
    if (!isNameCorrect(name))
        return false;

    auto it = getAssociativePairsIt(name);

    if (it == associativePairs_.end())
        return false;

    delete it->second;
    associativePairs_.erase(it);
    return true;
}

template <class T>
T*
AssociativePair<QString, T*>::
getValue(const QString& name) const
{
    if (!isNameCorrect(name))
        return nullptr;

    auto it = getAssociativePairsIt(name);

    if (it == associativePairs_.cend())
        return nullptr;

    return it->second;
}

template <class T>
QString
AssociativePair<QString, T*>::
getName(size_t i) const
{
    if (i >= static_cast<size_t>(associativePairs_.size()))
        return "";

    return associativePairs_[i].first;
}

template <class T>
void
AssociativePair<QString, T*>::
clear()
{
    qsizetype associativePairsSize = associativePairs_.size();

    for (qsizetype i = 0; i < associativePairsSize; ++i)
        delete associativePairs_[i].second;

    associativePairs_.clear();
}

template <class T>
bool
AssociativePair<QString, T*>::
find(const QString& name) const
{
    if (!isNameCorrect(name))
        return false;

    return getAssociativePairsIt(name) != associativePairs_.cend();
}

template <class T>
size_t
AssociativePair<QString, T*>::
size() const
{
    return associativePairs_.size();
}

template <class T>
typename AssociativePair<QString, T*>::AssocPairsIt
AssociativePair<QString, T*>::
getAssociativePairsIt(const QString& name)
{
    if (!isNameCorrect(name))
        return associativePairs_.end();

    return std::find_if(associativePairs_.begin(), associativePairs_.end(),
                        [&name](const std::pair<QString, T*>& assocPair) {
        return name == assocPair.first;
    });
}

template <class T>
typename AssociativePair<QString, T*>::AssocPairsCIt
AssociativePair<QString, T*>::
getAssociativePairsIt(const QString& name) const
{
    if (!isNameCorrect(name))
        return associativePairs_.cend();

    return std::find_if(associativePairs_.cbegin(), associativePairs_.cend(),
                        [&name](const std::pair<QString, T*>& assocPair) {
        return name == assocPair.first;
    });
}

template <class T>
bool
AssociativePair<QString, T*>::
isNameCorrect(const QString& name) const
{
    return name != "";
}

template <class T>
bool
AssociativePair<QString, T*>::
isValueCorrect(T* value) const
{
    return value != nullptr;
}
