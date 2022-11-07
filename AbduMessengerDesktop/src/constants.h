#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QRegularExpression>

class QSpacerItem;

namespace constants {

namespace regex {

extern const QRegularExpression UsernameValidation;
extern const QRegularExpression PasswordValidation;
extern const QRegularExpression NameValidation;

} // regex

namespace ui {

extern QSpacerItem *createVSpacer();
extern QSpacerItem *createHSpacer();

} // ui

} // constants

#endif // CONSTANTS_H
