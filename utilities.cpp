#include "utilities.hpp"
#include <iostream>

QString utilities::getCurrentDate()
{
    QDate d = QDate::currentDate();

    QString year = QString::number(d.year());
    QString month = d.month() < 10 ? "0" + QString::number(d.month()) : QString::number(d.month());
    QString day = d.day() < 10 ? "0" + QString::number(d.day()) : QString::number(d.day());


    QString cdate = year + "-" + month + "-" + day;

    return cdate;
}

