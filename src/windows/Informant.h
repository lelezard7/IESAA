#ifndef INFORMANT_H_
#define INFORMANT_H_

#include "StyleSheetCreator.h"

#include <QPushButton>
#include <QColor>
#include <QLabel>
#include <QLayout>
#include <QFrame>
#include <QScrollArea>
#include <QWidget>
//#include <QMediaPlayer>


class Message : public QWidget
{
    Q_OBJECT

    StyleSheetCreator styleSheetCreators_;

public:
    QWidget* getMessageWidget(const QString& message);

private:
    QString getStyleSheet_button_Close();
    QString getStyleSheet_message();

};


class Informant
{
    bool isViewed_;
    StyleSheetCreator styleSheetCreator_;
    QWidget* scrollAreaWidgetContents_;
    Message message_;
    QPushButton* pushButton_;

public:
    Informant();
    Informant(QPushButton* pushButton);
    virtual ~Informant();

    void setPushButton(QPushButton* pushButton);
    QPushButton* getPushButton() const;

    void setScrollAreaWidgetContents(QWidget* scrollAreaWidgetContents);
    QWidget* getScrollAreaWidgetContents() const;

    void setViewed(bool value);
    bool isViewed() const;

    void beep();

    bool sendInfoMessage(const QString& message);

protected:
    void setButtonColor(const QColor& color);

};

#endif
