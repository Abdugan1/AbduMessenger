#ifndef CONSOLE_H
#define CONSOLE_H

#include <QObject>
#include <QRunnable>
#include <QRect>

#include <ncurses.h>

class QMutex;

class Window;

enum Pages {
    MainMenu,
    ServerLogs
};

class Console : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Console(QMutex *serverLogsMutex);
    ~Console();

    void run() override;

signals:
    void requestStartServer();
    void requestStopServer();

public slots:
    void onServerEnabled();
    void onServerDisabled();

private:
    void printHeader();
    void printCurrentPage();

    void printMainMenu();
    void parseMainMenu(int choice);

    void printServerLogs();

private:
    QMutex *serverLogsMutex_ = nullptr;

    Window *headerWindow_  = nullptr;
    QString headerTitle_;

    Window *contentWindow_ = nullptr;
    Window *infoWindow_    = nullptr;

    Pages currentPage_ = MainMenu;
    bool run_ = true;
    bool serverEnabled_ = false;
};

#endif // CONSOLE_H
