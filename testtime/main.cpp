#include "mainwindow.h"
#include <QApplication>

#include <QTimer>
#include <QTime>
#include <QString>
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QString current = QTime::currentTime().toString();
    qDebug() << current;

    QString s = "11:10:00";
    QTime t1 = QTime::fromString(s);

    if (t1 < QTime::currentTime()) {
        std::cout << "less" << std::endl;
    }

    w.show();

    return a.exec();
}
