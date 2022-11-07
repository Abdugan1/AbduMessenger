#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

class ServerSocket;

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();

signals:
    void enabled();
    void disabled();

protected:
    void incomingConnection(qintptr socketDescriptor) override;

public slots:
    void start();
    void stop();

private slots:
    void onUserDisconnected();

private:
    void logMessage(const QString &str);

private:
    using ServerSockets = QList<ServerSocket *>;
    ServerSockets serverSockets_;

};

#endif // SERVER_H
