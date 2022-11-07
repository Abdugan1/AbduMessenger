#ifndef CLIENT_H
#define CLIENT_H

#include "AbduMessengerClient_global.h"

#include <QTcpSocket>

class QJsonObject;

class ABDUMESSENGERCLIENT_EXPORT Client : public QTcpSocket
{
    Q_OBJECT
public:
    static Client *instance();

    void connectToServer();

public slots:
    void login(const QString &username, const QString &password);

private:
    explicit Client(QObject *parent = nullptr);

    void sendRequest(const QJsonObject &json);
};

#define client Client::instance()

#endif // CLIENT_H
