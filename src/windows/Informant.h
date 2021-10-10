#ifndef INFORMANT_H_
#define INFORMANT_H_

#include <QPushButton>
#include <QColor>


class Informant
{
    bool isViewed_;

    QPushButton* pushButton_;

public:
    Informant();
    Informant(QPushButton* pushButton);
    virtual ~Informant();

    void setPushButton(QPushButton* pushButton);
    QPushButton* getPushButton() const;

    void setViewed(bool value);
    bool isViewed() const;

    bool sendInfoMessage(const QString& message);
    bool sendWarningMessage(const QString& message);
    bool sendErrorMessage(const QString& message);

protected:
    void setButtonColor(const QColor& color);

};

#endif
