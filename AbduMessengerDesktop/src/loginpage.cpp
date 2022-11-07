#include "loginpage.h"
#include "uiloginpage.h"

LoginPage::LoginPage(QWidget *parent)
    : QFrame{parent}
    , ui_(new UiLoginPage)
{
    ui_->setupUi(this);
}

LoginPage::~LoginPage()
{
    delete ui_;
}
