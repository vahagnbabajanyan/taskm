#include "mainwindow.h"
#include <QApplication>

#include "timers.hpp"
#include "calendar.hpp"

#include "sql_engine.hpp"
#include "task_timers.hpp"

template <typename T>
std::list<std::string> getTasks()
{
    std::list<std::string> result;
    result.push_back(taskName<cormen>().name);
    result.push_back(taskName<templates>().name);
    result.push_back(taskName<design_patterns>().name);
    result.push_back(taskName<alexandrescu>().name);
    result.push_back(taskName<threads>().name);
    result.push_back(taskName<work>().name);
    result.push_back(taskName<stroustrup>().name);
    result.push_back(taskName<satter_generic>().name);
    result.push_back(taskName<tests>().name);
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


    /*
    sqlc.create_table("test1");
    sqlc.insertTaskForDate("2015-01-29", "09:30", "templates", "60", "notStarted", "test1");
    sqlc.insertTaskForDate("2015-01-29", "10:30", "design patterns", "60", "notStarted", "test1");
    sqlc.insertTaskForDate("2015-01-29", "11:30", "satter", "60", "notStarted", "test1");
    sqlc.insertTaskForDate("2015-01-29", "13:00", "threads", "60", "notStarted", "test1");
    sqlc.insertTaskForDate("2015-01-29", "08:30", "cormen", "60", "notStarted", "test1");
    sqlc.insertTaskForDate("2015-01-29", "21:00", "stroustrup", "60", "notStarted", "test1");
    */

    QStringList tlist = sqlc.getTaskForDateByName("test1", "2015-01-29", "templates");
    task ts(tlist);
    myTimers timer;
    timer.setTimer(ts);
    timer.show();

    return a.exec();
}
