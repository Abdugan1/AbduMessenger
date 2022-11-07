#ifndef PASSWORDLINEEDIT_H
#define PASSWORDLINEEDIT_H

#include "lineedit.h"

class PasswordLineEdit : public LineEdit
{
    Q_OBJECT
public:
    explicit PasswordLineEdit(QWidget *parent = nullptr);
};

#endif // PASSWORDLINEEDIT_H
