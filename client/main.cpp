#include "mainwindow.h"
#include "queueupsong.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Internet Radio App");
    w.show();
    return a.exec();
}
