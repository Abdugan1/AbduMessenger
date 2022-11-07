#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include <QRect>

class Window
{
public:
    explicit Window(const QRect &rect);

    void refresh();
    int box(chtype horch, chtype verch);
    int print(int x, int y, const char *str);
    int wgetch();
    int setKeypadEnabled(bool enabled);
    void setNoDelay(bool enabled);

    const QRect &rect() const;

private:
    WINDOW *window_ = nullptr;
    QRect rect_;
};

#endif // WINDOW_H
