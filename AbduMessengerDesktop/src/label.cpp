#include "label.h"

Label::Label(QWidget *parent)
    : QLabel{parent}
{
    init();
}

Label::Label(const QString &text, QWidget *parent)
    : QLabel{text, parent}
{
    init();
}

bool Label::clickable() const
{
    return clickable_;
}

void Label::setClickable(bool newClickable)
{
    clickable_ = newClickable;
    setAttribute(Qt::WA_TransparentForMouseEvents, !clickable_);
}

void Label::mousePressEvent(QMouseEvent *event)
{
    QLabel::mousePressEvent(event);
    if (clickable_)
        emit pressed();
}

void Label::mouseReleaseEvent(QMouseEvent *event)
{
    QLabel::mouseReleaseEvent(event);
    if (clickable_)
        emit released();
}

void Label::init()
{
    setCursor(QCursor{Qt::PointingHandCursor});
    setClickable(false);
}
