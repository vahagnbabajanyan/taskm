#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QLCDNumber>

#include "timers.hpp"

myTimers::myTimers(QWidget* parent)
    : QWidget(parent)
    , _mainWidget(new QWidget)
    , _visibleWidget(0)
{}

void myTimers::setTimer(const task& t)
{
    taskGui*_taskGui = new taskGui;
    std::cout << "taskTime : " << qPrintable(t._taskTime) << std::endl;
    _taskGui->_startTime->setText(t._taskTime);
    _taskGui->_taskName->setText(t._taskName);
    _taskGui->_timer = new QLCDNumber;
    _taskGui->_timer->setDigitCount(8);
    _taskGui->_timer->display(t._duration);

    QHBoxLayout* wlayout = new QHBoxLayout;
    wlayout->addWidget(_taskGui->_startTime);
    wlayout->addWidget(_taskGui->_taskName);
    wlayout->addWidget(_taskGui->_start);
    wlayout->addWidget(_taskGui->_stop);
    wlayout->addWidget(_taskGui->_timer);
    _mainWidget->setLayout(wlayout);
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addWidget(_mainWidget);
    setLayout(mainLayout);
}

myTimers::~myTimers()
{}

