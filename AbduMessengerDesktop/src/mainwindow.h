#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class LoginPage;
class ConnectionErrorPage;
class QStackedWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

private:
    LoginPage *loginPage_ = nullptr;
    ConnectionErrorPage *connectionErrorPage_ = nullptr;
    QStackedWidget *stackedWidget_ = nullptr;
};

#endif // MAINWINDOW_H
