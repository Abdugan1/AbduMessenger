#include "connectionerrorpage.h"
#include "uinoconnectionpage.h"
#include "button.h"

#include <AbduMessengerClient/client.h>

ConnectionErrorPage::ConnectionErrorPage(QWidget *parent)
    : QFrame{parent}
    , ui_{new UiConnectionErrorPage}
{
    ui_->setupUi(this);

    connect(ui_->reconnectButton, &Button::clicked, this, []() {
        client->connectToServer();
    });
}
