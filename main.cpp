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
    result.push_back(taskName<satter_generic>().name._value);
    result.push_back(taskName<threads>().name._value);
    result.push_back(taskName<work>().name._value);
    result.push_back(taskName<stroustrup>().name._value);
    result.push_back(taskName<alexandrescu>().name._value);
    result.push_back(taskName<tests>().name._value);
    return result;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    std::cout << "blaaaaaaaaaa" << std::endl;

    sqlconnector sqlc("QMYSQL", "localhost", "", "vahagn", "gorilaz");
    sqlc.create_database("testQuery");
    sqlc.selectDatabase("testQuery");
    foreach(const QString& tn, sqlc.showTables()) {
        qDebug() << tn;
    }
    //sqlc.create_table("test1");


    /*sqlc.create_table("test2");
    sqlc.insertTaskForDate("2015-01-29", "08:30", "cormen", "60", "notStarted", "test2");
    sqlc.insertTaskForDate("2015-01-29", "09:30", "templates", "60", "notStarted", "test2");
    sqlc.insertTaskForDate("2015-01-29", "10:30", "design patterns", "60", "notStarted", "test2");
    sqlc.insertTaskForDate("2015-01-29", "11:30", "satter", "60", "notStarted", "test2");
    sqlc.insertTaskForDate("2015-01-29", "13:00", "threads", "60", "notStarted", "test2");
    sqlc.insertTaskForDate("2015-01-29", "21:00", "stroustrup", "60", "notStarted", "test2");*/

    //sqlc.insertTaskForDate("2015-01-29", "22:00", "alexandrescu", "60", "notStarted", "test2");
    // sqlc.insertTaskForDate("2015-01-29", "14:00", "work", "240", "notStarted", "test2");


    std::list<task> tasks;
    std::list<std::string> taskNames(getTasks());
    foreach( const std::string& taskName, taskNames) {
        std::cout << "query for " << taskName << std::endl;
        QStringList tlist = sqlc.getTaskForDateByName("test2", "2015-01-29", taskName.c_str());
        tasks.push_back(task(tlist));
    }


    myTimers timer(tasks);
    timer.show();

    return a.exec();
}
