#include "client.h"

#include <AbduMessengerLib/requestandreply.h>
#include <AbduMessengerLib/datastream.h>
#include <AbduMessengerLib/constants.h>

#include <QJsonObject>

Client *Client::instance()
{
    static Client singleton;
    return &singleton;
}

void Client::connectToServer()
{
    connectToHost(constants::server::Ip, constants::server::Port);
}

void Client::login(const QString &username, const QString &password)
{
    QJsonObject loginInfo;
    loginInfo[request::headers::Type] = request::types::Login;
    loginInfo[request::headers::Username] = username;
    loginInfo[request::headers::Password] = password;

    sendRequest(loginInfo);
}

Client::Client(QObject *parent)
    : QTcpSocket{parent}
{

}

void Client::sendRequest(const QJsonObject &json)
{
    DataStream datastream(this);
    datastream << json;
}
