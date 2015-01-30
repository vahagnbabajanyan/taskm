#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QLCDNumber>

#include "timers.hpp"

myTimers::myTimers(const std::list<task>& tasks,
                   QWidget* parent)
    : QWidget(parent)
    , _mainWidget(new QWidget)
    , _visibleWidget(0)
    , _currentTimer(new QTimer())
    , _idleTimer(new QTimer())
{
    setTimer(tasks);
    setActive(QTime::currentTime());
}

void myTimers::setTimer(const std::list<task>& tasks)
{
    QVBoxLayout* vlayout = new QVBoxLayout;
    foreach (const task& t, tasks) {
        taskGui*_taskGui = new taskGui;
        _taskGui->_startTime->setText(t._taskTime);
        _taskGui->_taskName->setText(t._taskName);
        _taskGui->_timer = new QLCDNumber;
        _taskGui->_timer->setDigitCount(8);
        _taskGui->_timer->display(t._duration);
        _taskGui->_endTime = new QTime(QTime::fromString(t._endTime));
        _tasks.push_back(_taskGui);

        QHBoxLayout* wlayout = new QHBoxLayout;
        wlayout->addWidget(_taskGui->_startTime);
        wlayout->addWidget(_taskGui->_taskName);
        wlayout->addWidget(_taskGui->_start);
        _taskGui->_start->setEnabled(false);
        wlayout->addWidget(_taskGui->_stop);
        _taskGui->_stop->setEnabled(false);
        wlayout->addWidget(_taskGui->_timer);
        vlayout->addLayout(wlayout);

        _taskGui->_start->setStyleSheet("QPushButton {"
                                        "color: blue;"
                                        "background-color: rgb(107, 165, 117);"
                                        "}"
                                        "QPushButton[enabled=\"false\"] {"
                                        "  color: white;"
                                        "background-color: rgb(106, 119, 108);"
                                        "}"
                                        );
        _taskGui->_stop->setStyleSheet("QPushButton {"
                                        "color: blue;"
                                        "background-color: rgb(107, 165, 117);"
                                        "}"
                                        "QPushButton[enabled=\"false\"] {"
                                        "  color: white;"
                                        "background-color: rgb(106, 119, 108);"
                                        "}"
                                        );

        QObject::connect(_currentTimer, SIGNAL(timeout()), this, SLOT(updateTimers()));
        QObject::connect(_taskGui->_start, SIGNAL(pressed()), this, SLOT(startCurrentTimer()));
        QObject::connect(_taskGui->_stop, SIGNAL(pressed()), this, SLOT(stopCurrentTimer()));
    }
    _mainWidget->setLayout(vlayout);
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addWidget(_mainWidget);
    setLayout(mainLayout);
}

void myTimers::setActive(const QTime& current)
{
    foreach (taskGui* t, _tasks) {
        if (QTime::fromString(t->_startTime->text()) <= current &&
            current < *(t->_endTime) ) {

            _activeTask = t;
            _currentTimerDuration->setHMS(0, t->_timer->intValue(), 0);
            _activeTask->_start->setEnabled(true);
            _activeTask->_stop->setEnabled(true);
            return;
        }
    }
}

myTimers::~myTimers()
{}

