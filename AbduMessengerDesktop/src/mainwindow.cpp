#include "mainwindow.h"
#include "loginpage.h"
#include "connectionerrorpage.h"

#include <AbduMessengerClient/client.h>

#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
    , loginPage_{new LoginPage}
    , connectionErrorPage_{new ConnectionErrorPage}
    , stackedWidget_{new QStackedWidget}
{
    stackedWidget_->addWidget(connectionErrorPage_);
    stackedWidget_->addWidget(loginPage_);
    stackedWidget_->setCurrentWidget(loginPage_);
    setCentralWidget(stackedWidget_);

    connect(client, &Client::errorOccurred, this, [this]() {
        stackedWidget_->setCurrentWidget(connectionErrorPage_);
    });

    connect(client, &Client::connected, this, [this]() {
        stackedWidget_->setCurrentWidget(loginPage_);
    });

    client->connectToServer();
}
