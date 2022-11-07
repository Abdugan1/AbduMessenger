#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <QTcpSocket>

class ServerSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit ServerSocket(QObject *parent = nullptr);
};

#endif // SERVERSOCKET_H
