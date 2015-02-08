#ifndef PLAN_HPP
#define PLAN_HPP

#include <QWidget>
#include <QTimeEdit>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QListView>
#include <QDate>

#include <iostream>

#include <list>
#include <map>
#include <memory>

struct taskInfo : public QWidget
{
    taskInfo()
        : _startTime(new QTimeEdit)
        , _endTime(new QTimeEdit)
        , _tasks(new QComboBox)
    {
        createTasks();
        QHBoxLayout* hl = new QHBoxLayout;
        hl->addWidget(_tasks);
        hl->addWidget(_startTime);
        hl->addWidget(_endTime);
        setLayout(hl);
    }

    QTimeEdit* _startTime;
    QTimeEdit* _endTime;
    QComboBox* _tasks;

    void createTasks()
    {
        _tasks->addItem(tr("puzzle"));
        _tasks->addItem(tr("cormen"));
        _tasks->addItem(tr("templates"));
        _tasks->addItem(tr("design patterns"));
        _tasks->addItem(tr("alexandescu: 101"));
        _tasks->addItem(tr("threads"));
        _tasks->addItem(tr("lunch"));
        _tasks->addItem(tr("work"));
        _tasks->addItem(tr("english"));
        _tasks->addItem(tr("rest"));
        _tasks->addItem(tr("geeksForGeeks"));
        _tasks->addItem(tr("stroustrup"));
        _tasks->addItem(tr("satter: Generic"));
        _tasks->addItem(tr("codding"));
        _tasks->addItem(tr("test"));
    }
};

class dayPlan : public QWidget
{
public:
    dayPlan()
        : _size(15)
    {
        initTable();
    }

private:
    void initTable()
    {
        QGridLayout* gl = new QGridLayout;
        for (int i = 0; i != _size; ++i){
            QHBoxLayout* hl = new QHBoxLayout;
            std::shared_ptr<taskInfo> ti(new taskInfo);
            QString name = ti->_tasks->itemText(i);
            ti->_tasks->setCurrentIndex(i);
            static_cast<QListView*>(ti->_tasks->view())->setSpacing(0);
            _tasks.insert(std::make_pair(name, ti));
            hl->addWidget(ti.get());
            gl->addLayout(hl, i, 0);
        }
        setLayout(gl);
    }

    void setForDate(const QDate* d)
    {
        d->dayOfWeek();
    }

private:
    std::map<QString, std::shared_ptr<taskInfo>> _tasks;
    int _size;
};

#endif // PLAN_HPP

