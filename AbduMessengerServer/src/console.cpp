#include "console.h"
#include "window.h"

#include <QMutexLocker>

Console::Console(QMutex *serverLogsMutex)
    : serverLogsMutex_{serverLogsMutex}
{
    initscr();

    int w;
    int h;
    getmaxyx(stdscr, h, w);

    curs_set(0);
    noecho();

    headerWindow_  = new Window{QRect{1, 1, w - 2, 1}};

    contentWindow_ = new Window{QRect{1, 2, w - 2, h - 3}};
    contentWindow_->setKeypadEnabled(true);
    contentWindow_->setNoDelay(true);

    infoWindow_ = new Window{QRect{w - 27, 5, 25, 5}};
}

Console::~Console()
{
    endwin();
}

void Console::run()
{
    box(stdscr, 0, 0);
    contentWindow_->box(0, 0);
    refresh();
    contentWindow_->refresh();
    while (1) {
        printCurrentPage();
        printHeader();
    }
}

void Console::onServerEnabled()
{
    serverEnabled_ = true;
}

void Console::onServerDisabled()
{
    serverEnabled_ = false;
}

void Console::printHeader()
{
    int x = headerWindow_->rect().width() / 2 - headerTitle_.length() / 2;
    int y = 0;
    headerWindow_->print(x, y, qPrintable(headerTitle_));
    headerWindow_->refresh();
}

void Console::printCurrentPage()
{
    switch (currentPage_) {
    case MainMenu:
        printMainMenu();
        break;
    case ServerLogs:
        printServerLogs();
        break;
    }
}

void Console::printMainMenu()
{
    headerTitle_ = "AbduMessengerServer";

    const int OptionsCount = 3;
    static const std::string options[OptionsCount] {
        "Start/Stop server",
        "Server logs",
        "Exit"
    };

    static int choice = 0;
    int x = 2;
    int y = 4;
    for (int i = 0; i < OptionsCount; ++i) {
        if (i == choice)
            contentWindow_->print(x, y++, ("> " + options[i]).c_str());
        else
            contentWindow_->print(x, y++, ("  " + options[i]).c_str());
    }

    // info
    infoWindow_->box(0, 0);
    infoWindow_->print(2, 1, (std::string("Server enabled: ") + (serverEnabled_ ? "true " : "false")).c_str());
    infoWindow_->print(2, 2, "IP: 255.255.255.255");
    infoWindow_->print(2, 3, "PORT: 2002");

    switch (contentWindow_->wgetch()) {
    case KEY_UP:
        choice = std::max(0, --choice);
        break;
    case KEY_DOWN:
        choice = std::min(OptionsCount - 1, ++choice);
        break;
    case 10: // Enter
        parseMainMenu(choice);
        break;
    }

    contentWindow_->refresh();
    infoWindow_->refresh();
}

void Console::parseMainMenu(int choice)
{
    switch (choice) {
    case 0:
        if (!serverEnabled_)
            emit requestStartServer();
        else
            emit requestStopServer();
        break;
    case 1:
        break;
    case 2:
        break;
    }
}

void Console::printServerLogs()
{
    headerTitle_ = "Server Logs";
}
