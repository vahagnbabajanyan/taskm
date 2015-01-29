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
{
    setTimer(tasks);
}

void myTimers::setTimer(const std::list<task>& tasks)
{
    QVBoxLayout* vlayout = new QVBoxLayout;
    foreach (const task& t, tasks) {
        taskGui*_taskGui = new taskGui;
        std::cout << "taskTime : " << qPrintable(t._taskTime) << std::endl;
        _taskGui->_startTime->setText(t._taskTime);
        _taskGui->_taskName->setText(t._taskName);
        _taskGui->_timer = new QLCDNumber;
        _taskGui->_timer->setDigitCount(8);
        _taskGui->_timer->display(t._duration);
        _tasks.push_back(_taskGui);

        QHBoxLayout* wlayout = new QHBoxLayout;
        wlayout->addWidget(_taskGui->_startTime);
        wlayout->addWidget(_taskGui->_taskName);
        wlayout->addWidget(_taskGui->_start);
        wlayout->addWidget(_taskGui->_stop);
        wlayout->addWidget(_taskGui->_timer);
        vlayout->addLayout(wlayout);
    }
    _mainWidget->setLayout(vlayout);
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addWidget(_mainWidget);
    setLayout(mainLayout);
}

myTimers::~myTimers()
{}

