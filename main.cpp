#include "mainwindow.h"
#include <QApplication>
#include <QThread>
#include <QtConcurrent/QtConcurrent>

#include "timers.hpp"
#include "calendar.hpp"

#include "sql_engine.hpp"
#include "task_timers.hpp"
#include "idletimetracker.hpp"

std::list<std::string> getTasks()
{
    std::list<std::string> result;
    result.push_back(taskName<cormen>().name._value);
    result.push_back(taskName<templates>().name._value);
    result.push_back(taskName<design_patterns>().name._value);
    result.push_back(taskName<alexandrescu>().name._value);
    result.push_back(taskName<threads>().name._value);
    result.push_back(taskName<work>().name._value);
    result.push_back(taskName<stroustrup>().name._value);
    result.push_back(taskName<satter_generic>().name._value);
    result.push_back(taskName<dictionary>().name._value);
    result.push_back(taskName<tests>().name._value);
    result.push_back(taskName<movie_half>().name._value);
    result.push_back(taskName<reading>().name._value);
    return result;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    sqlconnector sqlc("QMYSQL", "localhost", "", "vahagn", "gorilaz");
    sqlc.create_database("testApp1");
    sqlc.selectDatabase("testApp1");

    /*sqlc.create_table("testTbl11");
    sqlc.insertTaskForDate("2015-02-01", "08:30", "09:30", "cormen", "60", "notStarted", "testTbl11");
    sqlc.insertTaskForDate("2015-02-01", "09:30", "10:30", "templates", "60", "notStarted", "testTbl11");
    sqlc.insertTaskForDate("2015-02-01", "10:30", "11:30", "design patterns", "60", "notStarted", "testTbl11");
    sqlc.insertTaskForDate("2015-02-01", "11:30", "12:30", "alexandrescu", "60", "notStarted", "testTbl11");
    sqlc.insertTaskForDate("2015-02-01", "13:00", "14:00", "threads", "60", "notStarted", "testTbl11");
    sqlc.insertTaskForDate("2015-02-01", "14:00", "18:00", "work", "240", "notStarted", "testTbl11");
    sqlc.insertTaskForDate("2015-02-01", "21:00", "22:00", "stroustrup", "60", "notStarted", "testTbl11");
    sqlc.insertTaskForDate("2015-02-01", "22:00", "23:00", "satter", "60", "notStarted", "testTbl11");
    sqlc.insertTaskForDate("2015-02-01", "23:00", "00:00", "dictionary", "60", "notStarted", "testTbl11");
    sqlc.insertTaskForDate("2015-02-01", "00:00", "00:40", "test knowledge", "40", "notStarted", "testTbl11");
    sqlc.insertTaskForDate("2015-02-01", "00:40", "01:00", "movie half", "20", "notStarted", "testTbl11");
    sqlc.insertTaskForDate("2015-02-01", "01:00", "01:30", "reading", "30", "notStarted", "testTbl11");



    sqlc.create_table("testTbl9");
    sqlc.insertTaskForDate("2015-01-29", "17:32", "17:34", "cormen", "2", "notStarted", "testTbl9");
    sqlc.insertTaskForDate("2015-01-29", "17:34", "17:36", "templates", "2", "notStarted", "testTbl9");
    sqlc.insertTaskForDate("2015-01-29", "17:36", "17:38", "design patterns", "2", "notStarted", "testTbl9");
    sqlc.insertTaskForDate("2015-01-29", "17:38", "17:40", "alexandrescu", "2", "notStarted", "testTbl9");
    sqlc.insertTaskForDate("2015-01-29", "17:40", "17:42", "threads", "2", "notStarted", "testTbl9");
    sqlc.insertTaskForDate("2015-01-29", "17:42", "17:44", "work", "2", "notStarted", "testTbl9");
    sqlc.insertTaskForDate("2015-01-29", "17:44", "17:46", "stroustrup", "2", "notStarted", "testTbl9");
    sqlc.insertTaskForDate("2015-01-29", "17:46", "17:48", "satter", "2", "notStarted", "testTbl9");
    sqlc.insertTaskForDate("2015-01-29", "17:48", "17:50", "dictionary", "2", "notStarted", "testTbl9");
    sqlc.insertTaskForDate("2015-01-29", "17:50", "17:52", "test knowledge", "2", "notStarted", "testTbl9");
    sqlc.insertTaskForDate("2015-01-29", "17:52", "17:54", "movie half", "2", "notStarted", "testTbl9");
    sqlc.insertTaskForDate("2015-01-29", "17:54", "17:56", "reading", "2", "notStarted", "testTbl9");

    sqlc.create_table("testTbl10");
        sqlc.insertTaskForDate("2015-01-29", "19:22", "19:24", "cormen", "2", "notStarted", "testTbl10");
        sqlc.insertTaskForDate("2015-01-29", "19:24", "19:26", "templates", "2", "notStarted", "testTbl10");
        sqlc.insertTaskForDate("2015-01-29", "19:26", "19:28", "design patterns", "2", "notStarted", "testTbl10");
        sqlc.insertTaskForDate("2015-01-29", "19:28", "19:30", "alexandrescu", "2", "notStarted", "testTbl10");
        sqlc.insertTaskForDate("2015-01-29", "19:30", "19:32", "threads", "2", "notStarted", "testTbl10");
        sqlc.insertTaskForDate("2015-01-29", "19:32", "19:34", "work", "2", "notStarted", "testTbl10");
        sqlc.insertTaskForDate("2015-01-29", "19:34", "19:36", "stroustrup", "2", "notStarted", "testTbl10");
        sqlc.insertTaskForDate("2015-01-29", "19:36", "19:38", "satter", "2", "notStarted", "testTbl10");
        sqlc.insertTaskForDate("2015-01-29", "19:38", "19:40", "dictionary", "2", "notStarted", "testTbl10");
        sqlc.insertTaskForDate("2015-01-29", "19:40", "19:42", "test knowledge", "2", "notStarted", "testTbl10");
        sqlc.insertTaskForDate("2015-01-29", "19:42", "19:44", "movie half", "2", "notStarted", "testTbl10");
        sqlc.insertTaskForDate("2015-01-29", "19:44", "19:46", "reading", "2", "notStarted", "testTbl10");*/


    std::cout << "APPLICATION STARTED" << std::endl;
    std::list<task> tasks;
    std::list<std::string> taskNames(getTasks());
    foreach( const std::string& taskName, taskNames) {
        QStringList tlist = sqlc.getTaskForDateByName("testTbl11", "2015-02-01", taskName.c_str());
        tasks.push_back(task(tlist));
    }

    myTimers timer(tasks);
    IdleTracker itracker;
    QObject::connect(&itracker, SIGNAL(userIdle()), &timer, SLOT(startIdleTimer()), Qt::DirectConnection);
    // start tracking in new thread
    QtConcurrent::run(&itracker, &IdleTracker::track);

    QThread* trackThread = new QThread;
    QObject::connect(trackThread, SIGNAL(started()), &itracker, SLOT(track()));
    QObject::connect(trackThread, SIGNAL(finished()), &itracker, SLOT(deleteLater()));
    itracker.moveToThread(trackThread);
    trackThread->start();


    timer.show();

    return a.exec();
}
