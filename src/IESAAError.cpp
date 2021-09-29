#include "IESAAError.h"


IESAAError::
IESAAError()
    : code_(0x00000000) {}

IESAAError::
IESAAError(IESAAError&& other)
    : code_          (std::move(other.code_))
    , description_   (std::move(other.description_))
    , recommendation_(std::move(other.recommendation_))
{
    other.code_ = 0x00000000;
    other.description_.clear();
    other.description_.clear();
}

IESAAError::
~IESAAError() {}

void
IESAAError::
setCode(int value)
{
    code_ = value;
}

int
IESAAError::
getCode() const
{
    return code_;
}

void
IESAAError::
setDescription(std::string_view value)
{
    description_ = value.data();
}

QString
IESAAError::
getDescription() const
{
    return description_;
}

void
IESAAError::
setRecommendation(std::string_view value)
{
    recommendation_ = value.data();
}

QString
IESAAError::
getRecommendation() const
{
    return recommendation_;
}

void IESAAError::reset()
{
    code_ = 0x00000000;
    description_.clear();
    description_.clear();
}

IESAAError&
IESAAError::
operator=(IESAAError&& other)
{
    code_           = std::move(other.code_);
    description_    = std::move(other.description_);
    recommendation_ = std::move(other.recommendation_);

    other.code_ = 0x00000000;
    other.description_.clear();
    other.description_.clear();

    return *this;
}

IESAAError::operator bool() const
{
    return static_cast<bool>(code_);
}
