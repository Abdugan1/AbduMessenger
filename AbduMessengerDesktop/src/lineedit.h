#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>

class Label;
class QPropertyAnimation;

class LineEdit : public QLineEdit
{
    Q_OBJECT
    Q_PROPERTY(QColor borderColor WRITE setBorderColor)
public:
    explicit LineEdit(QWidget *parent = nullptr);

    void setLeftIcon(const QPixmap &icon);
    void setRightIcon(const QPixmap &icon);

    void setLeftIconClickable(bool clickable);
    void setRightIconClickable(bool clickable);

    Label *leftIcon() const;
    Label *rightIcon() const;

    void setBorderColor(const QColor &color);

protected:
    void focusInEvent(QFocusEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;

private:
    Label *leftIcon_  = nullptr;
    Label *rightIcon_ = nullptr;

    QPropertyAnimation *wrongInputAnimation_ = nullptr;
};

#endif // LINEEDIT_H
