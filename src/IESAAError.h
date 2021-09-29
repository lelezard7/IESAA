#ifndef IESAAERROR_H_
#define IESAAERROR_H_

#include <QString>
#include <string_view>


class IESAAError
{
    int code_;
    QString description_;
    QString recommendation_;

public:
    IESAAError();
    IESAAError(const IESAAError& other) = default;
    IESAAError(IESAAError&& other);
    virtual ~IESAAError();

    void setCode(int value);
    int getCode() const;

    void setDescription(std::string_view value);
    QString getDescription() const;

    void setRecommendation(std::string_view value);
    QString getRecommendation() const;

    void reset();

    IESAAError& operator=(const IESAAError& other) = default;
    IESAAError& operator=(IESAAError&& other);

    operator bool() const;

};

#endif
