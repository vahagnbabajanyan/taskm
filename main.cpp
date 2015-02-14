#include "mainwindow.h"
#include <QApplication>
#include <QThread>
#include <QtConcurrent/QtConcurrent>

#include "timers.hpp"
#include "calendar.hpp"

#include "sql_engine.hpp"
#include "task_timers.hpp"
#include "idletimetracker.hpp"
#include "utilities.hpp"

std::list<std::string> getTasks()
{
    std::list<std::string> result;
    //result.push_back("puzzles");
    result.push_back(taskName<cormen>().name._value);
    result.push_back(taskName<templates>().name._value);
    result.push_back(taskName<design_patterns>().name._value);
    result.push_back(taskName<alexandrescu>().name._value);
    result.push_back(taskName<lunch>().name._value);
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

/*std::list<std::string> getTasks()
{
    std::list<std::string> result;
    result.push_back(taskName<work>().name._value);
    result.push_back(taskName<lunch>().name._value);
    result.push_back("work1");
    result.push_back(taskName<templates>().name._value);
    result.push_back(taskName<design_patterns>().name._value);
    result.push_back(taskName<alexandrescu>().name._value);
    result.push_back(taskName<threads>().name._value);
    result.push_back(taskName<stroustrup>().name._value);
    result.push_back(taskName<satter_generic>().name._value);
    result.push_back(taskName<dictionary>().name._value);
    result.push_back(taskName<tests>().name._value);
    result.push_back(taskName<movie_half>().name._value);
    result.push_back(taskName<reading>().name._value);
    return result;
}*/

int main(int argc, char *argv[])
{
    std::cout << "APPLICATION STARTEDD" << std::endl;

    QApplication a(argc, argv);

    QString whost = "sql3.freesqldatabase.com";
    QString dbase = "sql366888";
    QString wuser = "sql366888";
    QString wpass = "yF5*gA8*";
    QString port = "3306";

    sqlconnector sqlc("QMYSQL", whost, dbase, wuser, wpass, port);
    //sqlc.selectDatabase("sql366888");
    sqlc.selectDatabase("sql366888");
    sqlc.create_table("planVersion2");

    sqlc.create_table("planVersion1");
    sqlc.insertTaskForDate("2015-02-14", "08:00", "09:30", "puzzles", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-14", "08:30", "09:30", "cormen", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-14", "09:30", "10:30", "templates", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-14", "10:30", "11:30", "design patterns", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-14", "11:30", "12:30", "alexandrescu", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-14", "12:30", "13:00", "lunch", "30", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-14", "13:00", "14:00", "threads", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-14", "14:00", "18:00", "work", "240", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-14", "21:00", "22:00", "stroustrup", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-14", "22:00", "23:00", "satter", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-14", "23:00", "00:00", "dictionary", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-14", "00:00", "00:40", "test knowledge", "40", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-14", "00:40", "01:00", "movie half", "20", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-14", "01:00", "01:30", "reading", "30", "notStarted", "planVersion2");


    sqlc.insertTaskForDate("2015-02-15", "08:00", "09:30", "puzzles", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-15", "08:30", "09:30", "cormen", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-15", "09:30", "10:30", "templates", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-15", "10:30", "11:30", "design patterns", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-15", "11:30", "12:30", "alexandrescu", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-15", "12:30", "13:00", "lunch", "30", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-15", "13:00", "14:00", "threads", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-15", "14:00", "18:00", "work", "240", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-15", "21:00", "22:00", "stroustrup", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-15", "22:00", "23:00", "satter", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-15", "23:00", "00:00", "dictionary", "60", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-15", "00:00", "00:40", "test knowledge", "40", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-15", "00:40", "01:00", "movie half", "20", "notStarted", "planVersion2");
    sqlc.insertTaskForDate("2015-02-15", "01:00", "01:30", "reading", "30", "notStarted", "planVersion2");


    std::list<task> tasks;
    std::list<std::string> taskNames(getTasks());
    foreach( const std::string& taskName, taskNames) {
        QString cdate = utilities::getCurrentDate();
        QStringList tlist = sqlc.getTaskForDateByName("planVersion2", utilities::getCurrentDate(), taskName.c_str());
        tasks.push_back(task(tlist));
    }
    sqlc.closeDb();

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

    timer.activateWindow();
    timer.setWindowFlags(Qt::WindowStaysOnTopHint);
    timer.show();


    return a.exec();
}

/*
 * if (!sqlc.updateTaskStatusForDate(utilities::getCurrentDate(), _activeTask->_taskName->text(),
                                     QString::number(_currentTimerDuration->minute()),
                                     QString::number(prc),
                                     "planVersion1")) {
            std::cout << "CANNOT UPDATE TABLE" << std::endl;
        }
 * */


















//sqlc.create_table("planVersion1");
/*sqlc.insertTaskForDate("2015-02-09", "08:00", "09:30", "puzzles", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-09", "08:30", "09:30", "cormen", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-09", "09:30", "10:30", "templates", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-09", "10:30", "11:30", "design patterns", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-09", "11:30", "12:30", "alexandrescu", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-09", "12:30", "13:00", "lunch", "30", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-09", "13:00", "14:00", "threads", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-09", "14:00", "18:00", "work", "240", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-09", "21:00", "22:00", "stroustrup", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-09", "22:00", "23:00", "satter", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-09", "23:00", "00:00", "dictionary", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-09", "00:00", "00:40", "test knowledge", "40", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-09", "00:40", "01:00", "movie half", "20", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-09", "01:00", "01:30", "reading", "30", "notStarted", "planVersion1");


sqlc.insertTaskForDate("2015-02-10", "08:00", "09:30", "puzzles", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-10", "08:30", "09:30", "cormen", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-10", "09:30", "10:30", "templates", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-10", "10:30", "11:30", "design patterns", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-10", "11:30", "12:30", "alexandrescu", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-10", "12:30", "13:00", "lunch", "30", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-10", "13:00", "14:00", "threads", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-10", "14:00", "18:00", "work", "240", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-10", "21:00", "22:00", "stroustrup", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-10", "22:00", "23:00", "satter", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-10", "23:00", "00:00", "dictionary", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-10", "00:00", "00:40", "test knowledge", "40", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-10", "00:40", "01:00", "movie half", "20", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-10", "01:00", "01:30", "reading", "30", "notStarted", "planVersion1");


sqlc.insertTaskForDate("2015-02-11", "08:00", "09:30", "puzzles", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-11", "08:30", "09:30", "cormen", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-11", "09:30", "10:30", "templates", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-11", "10:30", "11:30", "design patterns", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-11", "11:30", "12:30", "alexandrescu", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-11", "12:30", "13:00", "lunch", "30", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-11", "13:00", "14:00", "threads", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-11", "14:00", "18:00", "work", "240", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-11", "21:00", "22:00", "stroustrup", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-11", "22:00", "23:00", "satter", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-11", "23:00", "00:00", "dictionary", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-11", "00:00", "00:40", "test knowledge", "40", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-11", "00:40", "01:00", "movie half", "20", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-11", "01:00", "01:30", "reading", "30", "notStarted", "planVersion1");


sqlc.insertTaskForDate("2015-02-12", "08:00", "09:30", "puzzles", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-12", "08:30", "09:30", "cormen", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-12", "09:30", "10:30", "templates", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-12", "10:30", "11:30", "design patterns", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-12", "11:30", "12:30", "alexandrescu", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-12", "12:30", "13:00", "lunch", "30", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-12", "13:00", "14:00", "threads", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-12", "14:00", "18:00", "work", "240", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-12", "21:00", "22:00", "stroustrup", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-12", "22:00", "23:00", "satter", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-12", "23:00", "00:00", "dictionary", "60", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-12", "00:00", "00:40", "test knowledge", "40", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-12", "00:40", "01:00", "movie half", "20", "notStarted", "planVersion1");
sqlc.insertTaskForDate("2015-02-12", "01:00", "01:30", "reading", "30", "notStarted", "planVersion1");*/




























//sqlc.create_database("testApp1");

//sqlconnector sqlc("QMYSQL", "localhost", "", "vahagn", "gorilaz");

/*sqlc.create_table("testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:30", "09:32", "lunch", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:32", "09:34", "work", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:34", "09:36", "work1", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:36", "09:38", "templates", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:38", "09:40", "design patterns", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:40", "09:42", "threads", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:42", "09:44", "alexandrescu", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:44", "09:46", "stroustrup", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:46", "09:48", "satter", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:48", "09:49", "dictionary", "1", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:49", "09:50", "test knowledge", "1", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:50", "09:52", "movie half", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:50", "09:54", "reading", "2", "notStarted", "testTbl_14");*/

/*sqlc.create_table("testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:30", "09:32", "lunch", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:32", "09:34", "work", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:34", "09:36", "work1", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:36", "09:38", "templates", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:38", "09:40", "design patterns", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:40", "09:42", "threads", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:42", "09:44", "alexandrescu", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:44", "09:46", "stroustrup", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:46", "09:48", "satter", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:48", "09:49", "dictionary", "1", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:49", "09:50", "test knowledge", "1", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:50", "09:52", "movie half", "2", "notStarted", "testTbl_14");
    sqlc.insertTaskForDate("2015-02-05", "09:50", "09:54", "reading", "2", "notStarted", "testTbl_14");*/


//sqlc.insertTaskForDate("2015-02-04", "13:00", "14:00", "work1", "60", "notStarted", "testTbl_13");

/*sqlc.create_table("testTbl_17");
sqlc.insertTaskForDate("2015-02-08", "12:30", "13:00", "lunch", "30", "notStarted", "testTbl_17");
sqlc.insertTaskForDate("2015-02-08", "11:15", "12:30", "work", "60", "notStarted", "testTbl_17");
sqlc.insertTaskForDate("2015-02-08", "13:00", "14:00", "work1", "60", "notStarted", "testTbl_17");
sqlc.insertTaskForDate("2015-02-08", "14:00", "15:00", "templates", "60", "notStarted", "testTbl_17");
sqlc.insertTaskForDate("2015-02-08", "15:00", "15:00", "design patterns", "60", "notStarted", "testTbl_17");
sqlc.insertTaskForDate("2015-02-08", "17:00", "18:00", "threads", "60", "notStarted", "testTbl_17");
sqlc.insertTaskForDate("2015-02-08", "16:00", "17:00", "alexandrescu", "60", "notStarted", "testTbl_17");
sqlc.insertTaskForDate("2015-02-08", "21:00", "22:00", "stroustrup", "60", "notStarted", "testTbl_17");
sqlc.insertTaskForDate("2015-02-08", "22:00", "23:00", "satter", "60", "notStarted", "testTbl_17");
sqlc.insertTaskForDate("2015-02-08", "23:00", "00:00", "dictionary", "60", "notStarted", "testTbl_17");
sqlc.insertTaskForDate("2015-02-08", "00:00", "00:40", "test knowledge", "40", "notStarted", "testTbl_17");
sqlc.insertTaskForDate("2015-02-08", "00:40", "01:00", "movie half", "20", "notStarted", "testTbl_17");
sqlc.insertTaskForDate("2015-02-08", "01:00", "01:30", "reading", "30", "notStarted", "testTbl_17");*/




//sqlc.insertTaskForDate("2015-02-05", "12:30", "13:00", "lunch", "30", "notStarted", "testTbl_16");
/*sqlc.create_table("testTbl_16");
sqlc.insertTaskForDate("2015-02-05", "08:30", "09:30", "cormen", "60", "notStarted", "testTbl_16");
sqlc.insertTaskForDate("2015-02-05", "09:30", "10:30", "templates", "60", "notStarted", "testTbl_16");
sqlc.insertTaskForDate("2015-02-05", "10:30", "11:30", "design patterns", "60", "notStarted", "testTbl_16");
sqlc.insertTaskForDate("2015-02-05", "11:30", "12:30", "alexandrescu", "60", "notStarted", "testTbl_16");
sqlc.insertTaskForDate("2015-02-05", "12:30", "13:00", "lunch", "30", "notStarted", "testTbl_16");
sqlc.insertTaskForDate("2015-02-05", "13:00", "14:00", "threads", "60", "notStarted", "testTbl_16");
sqlc.insertTaskForDate("2015-02-05", "14:00", "18:00", "work", "240", "notStarted", "testTbl_16");
sqlc.insertTaskForDate("2015-02-05", "21:00", "22:00", "stroustrup", "60", "notStarted", "testTbl_16");
sqlc.insertTaskForDate("2015-02-05", "22:00", "23:00", "satter", "60", "notStarted", "testTbl_16");
sqlc.insertTaskForDate("2015-02-05", "23:00", "00:00", "dictionary", "60", "notStarted", "testTbl_16");
sqlc.insertTaskForDate("2015-02-05", "00:00", "00:40", "test knowledge", "40", "notStarted", "testTbl_16");
sqlc.insertTaskForDate("2015-02-05", "00:40", "01:00", "movie half", "20", "notStarted", "testTbl_16");
sqlc.insertTaskForDate("2015-02-05", "01:00", "01:30", "reading", "30", "notStarted", "testTbl_16");*/

/*
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
