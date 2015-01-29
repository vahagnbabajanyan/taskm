#ifndef TIMERS_HPP
#define TIMERS_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QLabel>
#include <QTime>
#include <QTimer>

#include <list>
#include <iostream>
#include <queue>

#include "sql_engine.hpp"

enum Status
{
    notStarted,
    inProgress,
    failed,
    successed
};

namespace {
    Status stringToStatus(const QString& s)
    {
        if ("notStarted" == s) {
            return notStarted;
        }
        if ("inProgress" == s){
            return inProgress;
        }
        if ("failed" == s) {
            return failed;
        }
        return successed;
    }
}

struct task
{
    task(const QStringList& t)
    : _taskDate(t[0])
    , _taskName(t[1])
    , _taskTime(t[2])
    , _duration(t[3].toInt())
    , _status(stringToStatus(t[4]))
    {}
    QString _taskDate;
    QString _taskTime;
    QString _taskName;
    int _duration;
    Status _status;
};

struct taskGui
{
    taskGui()
        :_taskName(new QLabel)
        , _startTime(new QLabel)
        ,_start(new QPushButton("start"))
        , _stop(new QPushButton("stop"))
        , _timer(0)
    {}

    ~taskGui()
    {
        delete _taskName;
        delete _startTime;
        delete _start;
        delete _stop;
        delete _timer;
    }

    QLabel* _taskName;
    QLabel* _startTime;
    QPushButton* _start;
    QPushButton* _stop;
    QLCDNumber* _timer;
};

class myTimers : public QWidget
{
    typedef QString DateName;
public:
    myTimers(QWidget* parent = 0);

public:
    void setTimer(const task& t);
    ~myTimers();

private:
    QWidget* _mainWidget;
    QWidget* _visibleWidget;
    std::list<taskGui*> _tasks;
};

#endif // TIMERS_HPP
