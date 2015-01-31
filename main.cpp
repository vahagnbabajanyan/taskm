#include "mainwindow.h"
#include <QApplication>

#include "timers.hpp"
#include "calendar.hpp"

#include "sql_engine.hpp"
#include "task_timers.hpp"

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

    /*sqlc.create_table("testTbl4");
    sqlc.insertTaskForDate("2015-01-29", "08:30", "09:30", "cormen", "60", "notStarted", "testTbl4");
    sqlc.insertTaskForDate("2015-01-29", "09:30", "10:30", "templates", "60", "notStarted", "testTbl4");
    sqlc.insertTaskForDate("2015-01-29", "10:30", "11:30", "design patterns", "60", "notStarted", "testTbl4");
    sqlc.insertTaskForDate("2015-01-29", "11:30", "12:30", "alexandrescu", "60", "notStarted", "testTbl4");
    sqlc.insertTaskForDate("2015-01-29", "13:00", "14:00", "threads", "60", "notStarted", "testTbl4");
    sqlc.insertTaskForDate("2015-01-29", "14:00", "18:00", "work", "240", "notStarted", "testTbl4");
    sqlc.insertTaskForDate("2015-01-29", "21:00", "22:00", "stroustrup", "60", "notStarted", "testTbl4");
    sqlc.insertTaskForDate("2015-01-29", "22:00", "23:00", "satter", "60", "notStarted", "testTbl4");
    sqlc.insertTaskForDate("2015-01-29", "23:00", "00:00", "dictionary", "50", "notStarted", "testTbl4");
    sqlc.insertTaskForDate("2015-01-29", "23:50", "00:40", "test knowledge", "40", "notStarted", "testTbl4");
    sqlc.insertTaskForDate("2015-01-29", "00:30", "01:00", "movie half", "40", "notStarted", "testTbl4");
    sqlc.insertTaskForDate("2015-01-29", "01:00", "01:30", "reading", "40", "notStarted", "testTbl4");*/


    std::list<task> tasks;
    std::list<std::string> taskNames(getTasks());
    foreach( const std::string& taskName, taskNames) {
        QStringList tlist = sqlc.getTaskForDateByName("testTbl4", "2015-01-29", taskName.c_str());
        tasks.push_back(task(tlist));
    }


    myTimers timer(tasks);
    timer.show();

    return a.exec();
}
