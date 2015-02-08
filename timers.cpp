#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QLCDNumber>
#include <QStyle>

#include "timers.hpp"
#include "utilities.hpp"

namespace {
    void updateButtonStyle(QPushButton*& b)
    {
        b->style()->unpolish(b);
        b->style()->polish(b);
        b->update();
        b->repaint();
    }
}

myTimers::myTimers(const std::list<task>& tasks,
                   QWidget* parent)
    : QWidget(parent)
    , _mainWidget(new QWidget)
    , _visibleWidget(0)
    , _currentTimer(new QTimer())
    , _currentTimerDuration(new QTime())
    , _idleTimerDuration(new QTime())
    , _activeTask(0)
    , _is_active(false)
    , _run_timer(false)
    , _run_idle_timer(false)
    , _idleTimer(new QTimer())
    , _idle_lcd(0)
    , _calendar(new QPushButton("Calendar"))
    , _plan(new dayPlan)
{
    QHBoxLayout* mainLayout = new QHBoxLayout;
    setTimer(tasks, mainLayout);
    mainLayout->addWidget(_calendar);
    _calendar->setCheckable(true);
    connect(_calendar, SIGNAL(toggled(bool)), _plan, SLOT(setVisible(bool)));
    setActive(QTime::currentTime());
    QHBoxLayout* globalLayout = new QHBoxLayout;
    globalLayout->addLayout(mainLayout);
    _plan->hide();
    setLayout(globalLayout);
}

void myTimers::setTimer(const std::list<task>& tasks, QHBoxLayout* mainLayout)
{
    QVBoxLayout* vlayout = new QVBoxLayout;
    foreach (const task& t, tasks) {
        taskGui*_taskGui = new taskGui;
        setCurrentTask(_taskGui, t);
        _tasks.push_back(_taskGui);
        QHBoxLayout* wlayout = new QHBoxLayout;
        createTaskLayout(wlayout, _taskGui);
        vlayout->addLayout(wlayout);
        setButtonsStyleshits(_taskGui->_start);
        setButtonsStyleshits(_taskGui->_stop);
        _taskGui->_timer->setStyleSheet("QLCDNumber "
                                        "{color: red; "
                                        "background-color: black}"
                                        );
        QObject::connect(_currentTimer, SIGNAL(timeout()), this, SLOT(updateTimers()), Qt::UniqueConnection);
        QObject::connect(_taskGui->_start, SIGNAL(pressed()), this, SLOT(startCurrentTimer()));
        QObject::connect(_taskGui->_stop, SIGNAL(pressed()), this, SLOT(stopCurrentTimer()));
        startTimer();
    }
    _idle_lcd = new QLCDNumber;
    _idle_lcd->setDigitCount(8);
    _idleTimerDuration->setHMS(0, 0, 0, 0);
    _idle_lcd->display(0);
    _idle_lcd->setStyleSheet("QLCDNumber "
                                    "{color: black; "
                                    "background-color: red}");
    vlayout->addWidget(_idle_lcd);
    _mainWidget->setLayout(vlayout);
    mainLayout->addWidget(_mainWidget);

}

void myTimers::setCurrentTask(taskGui* taskg, const task& t)
{
    taskg->_startTime->setText(t._taskTime);
    taskg->_taskName->setText(t._taskName);
    taskg->_timer = new QLCDNumber;
    taskg->_timer->setDigitCount(8);
    taskg->_timer->display(t._duration);
    taskg->_endTime = new QTime(QTime::fromString(t._endTime));
    taskg->_percent->setText("0.0");
    taskg->_start->setEnabled(false);
    taskg->_stop->setEnabled(false);
    taskg->_duration = t._duration;
    std::cout << "setting duration : " << taskg->_duration << std::endl;
}

void myTimers::createTaskLayout(QHBoxLayout* layout, taskGui* taskg)
{
    layout->addWidget(taskg->_startTime);
    layout->addWidget(taskg->_taskName);
    layout->addWidget(taskg->_percent);
    layout->addWidget(taskg->_start);
    layout->addWidget(taskg->_stop);
    layout->addWidget(taskg->_timer);

}

void myTimers::setButtonsStyleshits(QPushButton *button)
{
    button->setStyleSheet("QPushButton {"
                          "color: blue;"
                          "background-color: rgb(107, 165, 117);"
                          "}"
                          "QPushButton[enabled=\"false\"] {"
                          "  color: white;"
                          "background-color: rgb(106, 119, 108);"
                          "}"
                          "QPushButton[enabled=\"true\"] {"
                          "  color: white;"
                          "background-color: rgb(107, 165, 117);"
                          "}"
                          );
}

void myTimers::setActive(const QTime& current)
{

    if ((_activeTask && current >= *(_activeTask->_endTime))) {
        _activeTask->_start->setEnabled(false);
        updateButtonStyle(_activeTask->_start);
        _activeTask->_stop->setEnabled(false);
        updateButtonStyle(_activeTask->_stop);
        // collectResults()
        _is_active = false;
        _run_timer = false;
        QString whost = "sql3.freesqldatabase.com";
        QString dbase = "sql366888";
        QString wuser = "sql366888";
        QString wpass = "yF5*gA8*";
        QString port = "3306";
        //sqlconnector sqlc("QMYSQL", "localhost", "", "vahagn", "gorilaz");
        sqlconnector sqlc("QMYSQL", whost, dbase, wuser, wpass, port);
        sqlc.selectDatabase("sql366888");
        QString upDur = QString::number(_currentTimerDuration->minute());
        double prc = (double(_currentTimerDuration->minute()) / double(_activeTask->_duration)) * 100;
        if (!sqlc.updateTaskStatusForDate(utilities::getCurrentDate(), _activeTask->_taskName->text(),
                                     QString::number(_currentTimerDuration->minute()),
                                     QString::number(prc),
                                     "planVersion1")) {
            std::cout << "CANNOT UPDATE TABLE" << std::endl;
        }
        sqlc.closeDb();
        _activeTask = 0;
    }


    foreach (taskGui* t, _tasks) {
        if (QTime::fromString(t->_startTime->text()) <= current && (current < *(t->_endTime) || "00:00:00" == t->_endTime->toString().toStdString()) ) {
            if (!_is_active /*&& !_run_idle_timer*/) {

                // set Buttons Enabled
                t->_start->setEnabled(true);
                updateButtonStyle(t->_start);
                t->_stop->setEnabled(true);
                updateButtonStyle(t->_stop);

                _is_active = true;

                // set Timer Duration
                int minutes = t->_timer->intValue();
                if (minutes >= 60) {
                    _currentTimerDuration->setHMS(minutes / 60, minutes % 60, 0, 0);
                } else {
                    _currentTimerDuration->setHMS(0, minutes, 0, 0);
                }

                // set active task
                _activeTask = t;
            }
            return;
        }
    }
}

void myTimers::updateTimers()
{
    QTime current = QTime::currentTime();
    setActive(current);
    if (_is_active && _run_timer && !_run_idle_timer) {
        _currentTimerDuration->setHMS(_currentTimerDuration->addMSecs(-1).hour(),
                                      _currentTimerDuration->addMSecs(-1).minute(),
                                      _currentTimerDuration->addMSecs(-1).second(),
                                      _currentTimerDuration->addMSecs(-1).msec());
        _activeTask->_timer->display(_currentTimerDuration->toString(QString("hh:mm:ss")));
    }
    if (_run_idle_timer) {
        _idleTimerDuration->setHMS(_idleTimerDuration->addMSecs(1).hour(),
                                   _idleTimerDuration->addMSecs(1).minute(),
                                   _idleTimerDuration->addMSecs(1).second(),
                                   _idleTimerDuration->addMSecs(1).msec());
        _idle_lcd->display(_idleTimerDuration->toString(QString("hh:mm:ss")));
    }
}

myTimers::~myTimers()
{}

