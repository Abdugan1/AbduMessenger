#ifndef UILOGINPAGE_H
#define UILOGINPAGE_H


class LoginPage;
class LineEdit;
class PasswordLineEdit;
class Button;
class QHBoxLayout;
class QVBoxLayout;
class QLabel;

class UiLoginPage
{
public:
    QLabel *welcomeLabel = nullptr;

    QVBoxLayout *rightSideLayout = nullptr;
    QVBoxLayout *editLayout = nullptr;
    QLabel *loginLabel = nullptr;
    LineEdit *usernameEdit = nullptr;
    PasswordLineEdit *passwordEdit = nullptr;
    Button *loginButton = nullptr;

    QHBoxLayout *mainLayout = nullptr;

    void setupUi(LoginPage *loginPage);
};

#endif // UILOGINPAGE_H
