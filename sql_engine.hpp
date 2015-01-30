#ifndef SQL_ENGINE_HPP
#define SQL_ENGINE_HPP

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>

#include <iostream>

/*
Driver ("QMYSQL");
whost = "sql3.freesqldatabase.com";
dbase = "sql364893";
wuser = "sql364893";
wpass = "cT6*nF3%";
localHost = "localhost";
luser = "vahagn";
lpass = "gorilaz";
sb = "show databases;";
dbName = "";
used = "use testDB2;";
st = "show tables;";
*/

class sqlconnector
{
public:
    sqlconnector(const QString& driver, const QString& hostname,
                 const QString& dbname, const QString& username,
                 const QString& userpas);

    bool create_database(const QString& dbName);
    bool create_table(const QString& tblName);
    bool selectDatabase(const QString& dbName);
    QStringList showTables();
    QStringList getAllForDate(const QString& date, const QString& tblName);
    QStringList getTaskForDateAndTime(const QString& time, const QString& date, const QString& tblName);
    QStringList getTaskForDateByName(const QString& taskName, const QString& date, const QString& tblName);
    bool insertTaskForDate(const QString& date, const QString& startTime,
                           const QString& endTime, const QString& taskName,
                           const QString& duration, const QString& status,
                           const QString& tblName);
    QString getLastDate();

private:
    QSqlDatabase _database;
};

#endif // SQL_ENGINE_HPP
