#include "Informant.h"


QWidget*
Message::
getMessageWidget(const QString& message)
{
    QPushButton* button_Close = new QPushButton("X");
    button_Close->setStyleSheet(getStyleSheet_button_Close());

    QVBoxLayout* vlayout = new QVBoxLayout;
    vlayout->addWidget(button_Close);
    vlayout->addStretch();

    QLabel* label = new QLabel();
    label->setWordWrap(true);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    label->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    label->setText(message);

    QHBoxLayout* hlayout = new QHBoxLayout;
    hlayout->addWidget(label);
    hlayout->addLayout(vlayout);

    QFrame* frame = new QFrame;
    frame->setMinimumHeight(50);
    frame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    frame->setStyleSheet(getStyleSheet_message());
    frame->setLayout(hlayout);

    connect(button_Close, &QPushButton::clicked, frame, &QFrame::deleteLater);

    return frame;
}

QString
Message::
getStyleSheet_button_Close()
{
    styleSheetCreators_.setProperty("QPushButton", "border", "none");
    styleSheetCreators_.setProperty("QPushButton", "border-radius", "2px");
    styleSheetCreators_.setProperty("QPushButton", "width", "14px");
    styleSheetCreators_.setProperty("QPushButton", "height", "14px");
    styleSheetCreators_.setProperty("QPushButton", "text-align", "center");
    styleSheetCreators_.setProperty("QPushButton", "background-color", "#293133");
    styleSheetCreators_.setProperty("QPushButton", "color", "#f5f5f5");

    styleSheetCreators_.setProperty("QPushButton::hover", "background-color", "#f5f5f5");
    styleSheetCreators_.setProperty("QPushButton::hover", "color", "#293133");
    return styleSheetCreators_.getStyleSheet();
}

QString
Message::
getStyleSheet_message()
{
    styleSheetCreators_.setProperty("QFrame", "border", "none");
    styleSheetCreators_.setProperty("QFrame", "border-radius", "4px");
    styleSheetCreators_.setProperty("QFrame", "background-color", "#464451");
    styleSheetCreators_.setProperty("QFrame", "color", "#f5f5f5");
    return styleSheetCreators_.getStyleSheet();
}






Informant::
Informant()
    : isViewed_  (true)
    , pushButton_(nullptr)
{
//    setViewed(isViewed_);
}

Informant::
Informant(QPushButton* pushButton)
    : isViewed_  (true)
    , pushButton_(pushButton)
{
//    setViewed(isViewed_);
}

Informant::
~Informant() {}

void
Informant::
setPushButton(QPushButton* pushButton)
{
    pushButton_ = pushButton;
}

QPushButton*
Informant::
getPushButton() const
{
    return pushButton_;
}

void
Informant::
setScrollAreaWidgetContents(QWidget* scrollAreaWidgetContents)
{
    scrollAreaWidgetContents_ = scrollAreaWidgetContents;

    QVBoxLayout* contentsLayout = new QVBoxLayout;
    contentsLayout->addStretch();

    scrollAreaWidgetContents_->setLayout(contentsLayout);
}

QWidget*
Informant::
getScrollAreaWidgetContents() const
{
    return scrollAreaWidgetContents_;
}

void
Informant::
setViewed(bool value)
{
    StyleSheetCreator styleSheetCreator;

    if (value) {
        styleSheetCreator.setProperty("QPushButton", "background-color", "#9966cc");
        styleSheetCreator.setProperty("QPushButton", "border", "none");
        styleSheetCreator.setProperty("QPushButton::hover", "background-color", "#f5f5f5");
        pushButton_->setStyleSheet(styleSheetCreator.getStyleSheet());
        isViewed_ = value;
        return;
    }

    styleSheetCreator.setProperty("QPushButton", "background-color", "#ff033e");
    styleSheetCreator.setProperty("QPushButton", "border", "none");
    styleSheetCreator.setProperty("QPushButton::hover", "background-color", "#f5f5f5");
    pushButton_->setStyleSheet(styleSheetCreator.getStyleSheet());
    isViewed_ = value;
}

bool
Informant::
isViewed() const
{
    return isViewed_;
}

void
Informant::
beep()
{

}

bool
Informant::
sendInfoMessage(const QString& message)
{
    setViewed(false);

    int i = scrollAreaWidgetContents_->layout()->count();
    QVBoxLayout* layout = static_cast<QVBoxLayout*>(scrollAreaWidgetContents_->layout());
    layout->insertWidget(i - 1, message_.getMessageWidget(message));


    return true;
}

void
Informant::
setButtonColor(const QColor& color)
{
//    pushButton_->setStyleSheet()
}


