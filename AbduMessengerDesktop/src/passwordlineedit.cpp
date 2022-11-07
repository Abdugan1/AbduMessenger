#include "passwordlineedit.h"
#include "label.h"

#include <QStateMachine>

PasswordLineEdit::PasswordLineEdit(QWidget *parent)
    : LineEdit{parent}
{
    setLeftIcon(QPixmap{":/images/padlock_24.png"});
    setRightIcon(QPixmap{":/images/show_password_24.png"});

    setRightIconClickable(true);

    QStateMachine *stateMachine = new QStateMachine{this};
    QState *hiddenPasswordState = new QState;
    QState *shownPasswordState = new QState;

    hiddenPasswordState->assignProperty(this, "echoMode", QLineEdit::Password);
    hiddenPasswordState->assignProperty(this->rightIcon(), "pixmap", QPixmap{":/images/show_password_24.png"});
    hiddenPasswordState->addTransition(this->rightIcon(), &Label::pressed, shownPasswordState);

    shownPasswordState->assignProperty(this, "echoMode", QLineEdit::Normal);
    shownPasswordState->assignProperty(this->rightIcon(), "pixmap", QPixmap{":/images/hide_password_24.png"});
    shownPasswordState->addTransition(this->rightIcon(), &Label::pressed, hiddenPasswordState);

    stateMachine->addState(hiddenPasswordState);
    stateMachine->addState(shownPasswordState);
    stateMachine->setInitialState(hiddenPasswordState);
    stateMachine->start();
}
