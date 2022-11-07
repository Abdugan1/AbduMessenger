#include "uiloginpage.h"
#include "loginpage.h"
#include "lineedit.h"
#include "passwordlineedit.h"
#include "button.h"
#include "constants.h"

#include <QBoxLayout>
#include <QLabel>
#include <QRegularExpressionValidator>
#include <QMovie>

inline void setPointSize(QWidget *w, int pointSize)
{
    w->setFont(QFont{w->font().family(), pointSize});
}

void UiLoginPage::setupUi(LoginPage *loginPage)
{
    welcomeLabel = new QLabel;
    welcomeLabel->setMovie(new QMovie{":/images/welcome.gif", QByteArray(), welcomeLabel});
    welcomeLabel->movie()->start();

    // edit layout
    loginLabel = new QLabel{QObject::tr("Login")};
    setPointSize(loginLabel, 18);

    usernameEdit = new LineEdit;
    usernameEdit->setPlaceholderText(QObject::tr("Username"));
    usernameEdit->setValidator(new QRegularExpressionValidator{constants::regex::UsernameValidation});
    usernameEdit->setLeftIcon(QPixmap{":/images/user_24.png"});

    passwordEdit = new PasswordLineEdit;
    passwordEdit->setPlaceholderText(QObject::tr("Password"));
    passwordEdit->setValidator(new QRegularExpressionValidator{constants::regex::PasswordValidation});

    loginButton = new Button{QObject::tr("LOG IN")};

    editLayout = new QVBoxLayout;
    editLayout->setSpacing(5);
    editLayout->addWidget(loginLabel);
    editLayout->addWidget(usernameEdit);
    editLayout->addWidget(passwordEdit);
    editLayout->addWidget(loginButton);

    rightSideLayout = new QVBoxLayout;
    rightSideLayout->setMargin(5);
    rightSideLayout->addSpacerItem(constants::ui::createVSpacer());
    rightSideLayout->addLayout(editLayout);
    rightSideLayout->addSpacerItem(constants::ui::createVSpacer());

    // main layout
    mainLayout = new QHBoxLayout;
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->addWidget(welcomeLabel);
    mainLayout->addLayout(rightSideLayout);

    loginPage->setObjectName("loginPage");
    loginPage->setLayout(mainLayout);

}
