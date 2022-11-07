#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QFrame>

class UiLoginPage;

class LoginPage : public QFrame
{
    Q_OBJECT
public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private:
    UiLoginPage *ui_ = nullptr;

};

#endif // LOGINPAGE_H
