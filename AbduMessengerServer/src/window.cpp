#include "window.h"

Window::Window(const QRect &rect)
{
    rect_ = rect;
    window_ = newwin(rect.height(), rect.width(), rect.y(), rect.x());
}

void Window::refresh()
{
    wrefresh(window_);
}

int Window::box(chtype horch, chtype verch)
{
    return ::box(window_, verch, horch);
}

int Window::print(int x, int y, const char *str)
{
    return mvwprintw(window_, y, x, str);
}

int Window::wgetch()
{
    return ::wgetch(window_);
}

int Window::setKeypadEnabled(bool enabled)
{
    return keypad(window_, enabled);
}

void Window::setNoDelay(bool enabled)
{
    nodelay(window_, enabled);
}

const QRect &Window::rect() const
{
    return rect_;
}
