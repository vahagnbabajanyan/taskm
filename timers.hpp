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
    , _endTime(t[3])
    , _duration(t[4].toInt())
    , _status(stringToStatus(t[5]))
    , _percent(t[6].toDouble())
    {}

public:
    QString _taskDate;
    QString _taskTime;
    QString _endTime;
    QString _taskName;
    int _duration;
    Status _status;
    double _percent;
};

struct taskGui
{
    taskGui()
        :_taskName(new QLabel)
        , _startTime(new QLabel)
        , _endTime(new QTime)
        ,_start(new QPushButton("start"))
        , _stop(new QPushButton("stop"))
        , _timer(0)
        , _percent(new QLabel)
        , _duration(0)

    {}

    ~taskGui()
    {
        delete _taskName;
        delete _startTime;
        delete _start;
        delete _stop;
        if (0 != _timer) {
            delete _timer;
        }
        delete _percent;

    }

    QLabel *_taskName;
    QLabel *_startTime;
    QTime *_endTime;
    QPushButton *_start;
    QPushButton *_stop;
    QLCDNumber *_timer;
    QLabel *_percent;
    int _duration;
};


class myTimers : public QWidget
{
    Q_OBJECT

    typedef QString DateName;
public:
    myTimers(const std::list<task>& tasks,
             QWidget* parent = 0);
    void setTimer(const std::list<task>& tasks);
    ~myTimers();

private slots:
    void updateTimers();

    void startTimer()
    {
        // calibration
        _currentTimer->start(1);
    }

public slots:
    void startCurrentTimer()
    {
        // calibration
        _run_timer = true;
        _run_idle_timer = false;
    }

    void stopCurrentTimer()
    {
        _run_timer = false;
        _run_idle_timer = true;
    }

    void startIdleTimer()
    {
        std::cout << "IDLE TIMER STARTED" <<  std::endl;
        _run_idle_timer = true;
        _run_timer = false;
    }

private:
    void setActive(const QTime& current);
    void setButtonsStyleshits(QPushButton* button);
    void setCurrentTask(taskGui* taskGui, const task& t);
    void createTaskLayout(QHBoxLayout* layout, taskGui* taskg);

private:
    QWidget* _mainWidget;
    QWidget* _visibleWidget;
    std::list<taskGui*> _tasks;

    taskGui* _activeTask;
    bool _is_active;
    bool _run_timer;
    taskGui* _idleTask;
    bool _run_idle_timer;
    QLCDNumber* _idle_lcd;

    QTimer* _currentTimer;
    QTime* _currentTimerDuration;
    QTimer* _idleTimer;
    QTime* _idleTimerDuration;
};

#endif // TIMERS_HPP
