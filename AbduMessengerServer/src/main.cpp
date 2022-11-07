#include <QCoreApplication>
#include <QThreadPool>
#include <QMutex>

#include "console.h"
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QMutex serverLogsMutex;

    auto threadPool = QThreadPool::globalInstance();

    Console *runnable = new Console(&serverLogsMutex);
    runnable->setAutoDelete(true);

    threadPool->start(runnable);

    Server server;

    QObject::connect(runnable, &Console::requestStartServer, &server, &Server::start);
    QObject::connect(runnable, &Console::requestStopServer,  &server, &Server::stop);
    QObject::connect(&server, &Server::enabled,  runnable, &Console::onServerEnabled);
    QObject::connect(&server, &Server::disabled, runnable, &Console::onServerDisabled);

    return app.exec();
}
