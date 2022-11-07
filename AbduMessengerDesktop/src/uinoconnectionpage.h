#ifndef UINOCONNECTIONPAGE_H
#define UINOCONNECTIONPAGE_H

class ConnectionErrorPage;

class QLabel;
class Button;
class QHBoxLayout;
class QVBoxLayout;

class UiConnectionErrorPage
{
public:
    QLabel *imageLabel  = nullptr;
    QLabel *titleLabel  = nullptr;
    QLabel *reasonLabel = nullptr;
    Button *reconnectButton = nullptr;
    QVBoxLayout *mainLayout = nullptr;

    void setupUi(ConnectionErrorPage * noConnectionPage);
};

#endif // UINOCONNECTIONPAGE_H
