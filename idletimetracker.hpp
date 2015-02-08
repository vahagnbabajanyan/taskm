#ifndef IDLETIMETRACKER_HPP
#define IDLETIMETRACKER_HPP

#include <windows.h>
#include <WinUser.h>
#include <iostream>

#include <QObject>
#include <QThread>

BOOL WINAPI GetLastInputInfo(
    _Out_  PLASTINPUTINFO plii
    );

class IdleTracker : public QObject
{
    Q_OBJECT
public:
    IdleTracker()
        : QObject(0)
        , _mseconds(0)
        , _is_idle(false)
    {}

public slots:
    void track()
    {
        while (1) {
            //QThread::currentThread()->wait(1);
            _mseconds = GetIdleMS();
            if (_mseconds >= 300000 && false == _is_idle) {
                _is_idle = true;
                emit userIdle();
            }
            if (_mseconds < 300000 && _is_idle) {
                _is_idle = false;
            }

        }
    }

    UINT GetIdleMS()
    {
        LASTINPUTINFO li = { 0 };
        li.cbSize = sizeof(LASTINPUTINFO);
        GetLastInputInfo(&li);
        return GetTickCount() - li.dwTime;
    }

signals:
    void userIdle();
    void userActive();

private:
    UINT _mseconds;
    bool _is_idle;
};

#endif // IDLETIMETRACKER_HPP

