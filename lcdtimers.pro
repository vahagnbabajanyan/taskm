#-------------------------------------------------
#
# Project created by QtCreator 2015-01-20T09:44:16
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lcdtimers
debug: TARGET = lcdtimersD
TEMPLATE = app

LIBS += -luser32

SOURCES += main.cpp\
        mainwindow.cpp \
    timers.cpp \
    appwindow.cpp \
    calendar.cpp \
    sql_engine.cpp \
    utilities.cpp

HEADERS  += mainwindow.h \
    timers.hpp \
    appwindow.hpp \
    calendar.hpp \
    json.hpp \
    sql_engine.hpp \
    utilities.hpp \
    task_timers.hpp \
    idletimetracker.hpp \
    plan.hpp

FORMS    += mainwindow.ui
