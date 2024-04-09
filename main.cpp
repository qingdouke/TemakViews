#include "mainwindow.h"
#include <QtWidgets>
#include <QApplication>
#include "server.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator_cn;
    //Server server;
    if(translator_cn.load("temak_cn.qm"))
    {
       a.installTranslator(&translator_cn);
    }
    MainWindow w;

    w.move(0,0);
    w.show();

    return a.exec();
}
