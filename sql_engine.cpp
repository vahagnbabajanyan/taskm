#include "sql_engine.hpp"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>

namespace {
    QStringList get_list_from_query(QSqlQuery& query)
    {
        QStringList result;
        while(query.next());
           {
               if(query.isActive()) {
                   QMessageBox::information(0,"Good Query", "Good Query.  It\'s active");
                   qDebug() << query.value(0).toString();
                   result.push_back(query.value(0).toString());

               } else {
                   QMessageBox::warning(0, "Bad Query", "Bad Query, It\'s inactive");
               }
           }
        return result;
    }
}

sqlconnector::sqlconnector(const QString& driver, const QString& hostname,
             const QString& dbname, const QString& username,
             const QString& userpass)
                : _database(QSqlDatabase::addDatabase(driver))
{
    if (!dbname.isEmpty()) {
        _database.setDatabaseName(dbname);
    }
    if (!hostname.isEmpty()) {
        _database.setHostName(hostname);
    }
    if (!username.isEmpty()) {
        _database.setUserName(username);
    }
    if (!userpass.isEmpty()) {
        _database.setPassword(userpass);
    }
    if (!_database.open()) {
        qDebug() << _database.lastError().text();
    }
}

bool sqlconnector::create_database(const QString& dbname)
{
    QString create_db = "create database " + dbname + ";";
    QSqlQuery query(_database);
    if (!query.exec(create_db)) {
        qDebug() << query.lastError().text();
        return false;
    }
    return true;
}

bool sqlconnector::selectDatabase(const QString &dbName)
{
    QSqlQuery query(_database);
    if (!query.exec("use " + dbName + ";")) {
        qDebug() << query.lastError().text();
        return false;
    }
    return true;
}

bool sqlconnector::create_table(const QString& tblName)
{
    QString create_table = "CREATE TABLE IF NOT EXISTS " + tblName + " (" +
            "date DATE NOT NULL,"
            "task  VARCHAR(20),"
            "startTime TIME,"
            "endTime TIME,"
            "duration INT,"
            "status VARCHAR(20),"
            "percent DOUBLE"
            ");";
    QSqlQuery query(_database);
    if (!query.exec(create_table)) {
        qDebug() << query.lastError().text();
        return false;
    }
    return true;
}

QStringList sqlconnector::showTables()
{

    return _database.tables();
}

QStringList sqlconnector::getAllForDate(const QString& date, const QString& tblName)
{
    QString getDataForDate = "select * from " + tblName + " where date = " + date + ";"; // format 2015-05-06 YYYY-MM-DD
    QSqlQuery query(_database);
    if (!query.exec(getDataForDate)) {
        qDebug() << query.lastError().text();
        return QStringList();
    }
    return get_list_from_query(query);
}

QStringList sqlconnector::getTaskForDateAndTime(const QString& timeStart, const QString& date, const QString& tblName) // hh:mm:ss
{
    QString selectForTask = "select * from " + tblName + " where date = " + date + " and starttime = " + timeStart + ";";
    QSqlQuery query(_database);
    if (!query.exec(selectForTask)) {
        qDebug() << query.lastError().text();
        return QStringList();
    }
    return get_list_from_query(query);
}

QStringList sqlconnector::getTaskForDateByName(const QString& tblName, const QString& date, const QString& taskName)
{
    QString selectForTask = "select * from " + tblName + " where date = \"" + date + "\" and task = \"" + taskName + "\";";
    QSqlQuery query(_database);
    if (!query.exec(selectForTask)) {
        qDebug() << query.lastError().text();
        return QStringList();
    }
    query.next();
    QStringList result;
    result.push_back(query.value(0).toString());
    result.push_back(query.value(1).toString());
    result.push_back(query.value(2).toString());
    result.push_back(query.value(3).toString());
    result.push_back(query.value(4).toString());
    result.push_back(query.value(5).toString());
    result.push_back(query.value(6).toString());
    return result;
}

bool sqlconnector::insertTaskForDate(const QString& date, const QString& startTime, const QString& endTime,
                                     const QString& taskName, const QString& duration, const QString& status,
                                     const QString& tblName)
{
    QString qinsert = "insert into " + tblName + " (date, task, starttime, endTime, duration, status) VALUES(\"" +
            date + "\", \"" +
            taskName  + "\", \"" +
            startTime + "\", \"" +
            endTime + "\", \"" +
            duration + "\", \"" +
            status + "\");";
    QSqlQuery query(_database);
    if (!query.exec(qinsert)) {
        qDebug() << query.lastError().text();
        return false;
    }
    return true;
}

QString sqlconnector::getLastDate()
{
    return QString();
}


