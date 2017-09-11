#include "mainwindow.h"
#include <QtGui>
#include<QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("ANSI"));
    return a.exec();
}
