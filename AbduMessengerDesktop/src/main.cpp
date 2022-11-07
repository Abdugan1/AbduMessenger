#include <QApplication>
#include "mainwindow.h"

#include <QFile>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFontDatabase::addApplicationFont(":/fonts/Montserrat-Regular.ttf");
    app.setFont(QFont{"Montserrat"});

    QFile qssFile(":/qss/style.qss");
    qssFile.open(QFile::ReadOnly);
    app.setStyleSheet(QLatin1String(qssFile.readAll()));

    MainWindow window;
    window.show();

    return app.exec();
}
