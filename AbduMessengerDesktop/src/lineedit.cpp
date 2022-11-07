#include "lineedit.h"
#include "label.h"

#include <QBoxLayout>
#include <QPropertyAnimation>

inline const int Margin = 10;

LineEdit::LineEdit(QWidget *parent)
    : QLineEdit{parent}
    , leftIcon_{new Label}
    , rightIcon_{new Label}
{
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->setContentsMargins(Margin, 0, Margin, 0);
    hLayout->addWidget(leftIcon_);
    hLayout->addSpacerItem(new QSpacerItem{1, 1, QSizePolicy::Expanding, QSizePolicy::Maximum});
    hLayout->addWidget(rightIcon_);

    setLayout(hLayout);

    wrongInputAnimation_ = new QPropertyAnimation(this, "borderColor");
    wrongInputAnimation_->setDuration(300);
    wrongInputAnimation_->setStartValue(QColor{0, 0, 0});
    wrongInputAnimation_->setEndValue(QColor{255, 0, 0});

}

void LineEdit::setLeftIcon(const QPixmap &icon)
{
    leftIcon_->setPixmap(icon);
    auto margins = textMargins();
    margins.setLeft(icon.width() + Margin * 2);
    setTextMargins(margins);
}

void LineEdit::setRightIcon(const QPixmap &icon)
{
    rightIcon_->setPixmap(icon);
    auto margins = textMargins();
    margins.setRight(icon.width() + Margin * 2);
    setTextMargins(margins);
}

void LineEdit::setLeftIconClickable(bool clickable)
{
    leftIcon_->setClickable(clickable);
}

void LineEdit::setRightIconClickable(bool clickable)
{
    rightIcon_->setClickable(clickable);
}

Label *LineEdit::leftIcon() const
{
    return leftIcon_;
}

Label *LineEdit::rightIcon() const
{
    return rightIcon_;
}

void LineEdit::setBorderColor(const QColor &color)
{
    QLineEdit::setStyleSheet(QString("LineEdit{border: 1px solid rgb(%1, %2, %3)}")
                             .arg(color.red()).arg(color.green()).arg(color.blue()));
}

void LineEdit::focusInEvent(QFocusEvent *event)
{
    setBorderColor(QColor{0, 0, 0});
    QLineEdit::focusInEvent(event);
}

void LineEdit::focusOutEvent(QFocusEvent *event)
{
    if (validator() && !hasAcceptableInput())
        wrongInputAnimation_->start();
    QLineEdit::focusOutEvent(event);
}
