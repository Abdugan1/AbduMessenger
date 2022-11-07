#include "server.h"
#include "serversocket.h"

#include <AbduMessengerLib/constants.h>

Server::Server(QObject *parent)
    : QTcpServer{parent}
{
}

Server::~Server()
{
    if (isListening())
        stop();
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    ServerSocket *serverSocket = new ServerSocket{this};

    if (!serverSocket->setSocketDescriptor(socketDescriptor)) {
        serverSocket->deleteLater();
        return;
    }

    serverSockets_.append(serverSocket);

//    connect(serverSocket, &ServerSocket::disconnected)
}

void Server::start()
{
    bool ok = listen(QHostAddress::Any, constants::server::Port);
    if (ok) {
        emit enabled();
        logMessage("Server started");
    } else {
        logMessage("ERROR. Cannot start server");
    }
}

void Server::stop()
{
    for (auto *serverSocket : qAsConst(serverSockets_)) {
        serverSocket->disconnectFromHost();
        serverSocket->deleteLater();
    }
    serverSockets_.clear();
    close();

    emit disabled();
    logMessage("Server stopped");
}

void Server::onUserDisconnected()
{
    ServerSocket *disconnectedUser = qobject_cast<ServerSocket *>(sender());
    serverSockets_.removeAll(disconnectedUser);
}

void Server::logMessage(const QString &str)
{

}

