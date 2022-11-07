#include "constants.h"

#include <QSpacerItem>

namespace constants {

namespace regex {

const QRegularExpression UsernameValidation = QRegularExpression("^[a-zA-Z0-9]([\\._-](?![\\._-])|[a-zA-Z0-9]){2,18}[a-zA-Z0-9]$");
const QRegularExpression PasswordValidation = QRegularExpression("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z\\d]{8,}$");
const QRegularExpression NameValidation     = QRegularExpression("^[a-z][a-z ,\\.'-]+[a-z\\.]$");
} // regex

namespace ui {

QSpacerItem *createVSpacer()
{
    return new QSpacerItem{1, 1, QSizePolicy::Maximum, QSizePolicy::Expanding};
}

QSpacerItem *createHSpacer()
{
    return new QSpacerItem{1, 1, QSizePolicy::Expanding, QSizePolicy::Maximum};
}

} // ui

} // constants
