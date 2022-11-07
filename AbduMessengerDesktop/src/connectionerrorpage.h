#ifndef CONNECTIONERRORPAGE_H
#define CONNECTIONERRORPAGE_H

#include <QFrame>

class UiConnectionErrorPage;

class ConnectionErrorPage : public QFrame
{
    Q_OBJECT
public:
    explicit ConnectionErrorPage(QWidget *parent = nullptr);

private:
    UiConnectionErrorPage *ui_ = nullptr;
};

#endif // CONNECTIONERRORPAGE_H
