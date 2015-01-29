#ifndef JSON_HPP
#define JSON_HPP

#include <iostream>
#include <fstream>
#include <string>

#include <QStringList>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStringList>
#include <QObject>
#include <QJsonParseError>
#include <QDebug>

enum Key
{
    TASK,
    TIME,
    DURATION,
    STATUS
};

struct taskName
{
    static const Key _key = TASK;
    QString _value;
};

struct startTime
{
    static const Key _key = TIME;
    QString _value;
};

struct duration
{
    static const Key _key = DURATION;
    QString _value;
};

struct status
{
    static const Key _key = STATUS;
    QString _value;
};

namespace {
    QString toString(Key s)
    {
        if (Key::TASK == s) {
            return "taskName";
        }
        if (Key::TIME == s) {
            return "startTime";
        }
        if (Key::DURATION == s) {
            return "duration";
        }
        return "status";
    }
} // end of namespace


class jsonReader
{
public:
        jsonReader(const QString& jsonString)
        {
            QJsonParseError jerror;
            _json = QJsonDocument::fromJson(jsonString.toUtf8(), &jerror);
        }

        template <typename T>
        QString getValue()
        {
            QJsonObject jsonObject = _json.object();
            return jsonObject[toString(T::_key)].toString();
        }

private:
        QJsonDocument _json;
};

class jsonWriter
{
public:
    template <typename T>
    void addElement(const QString& s)
    {
        if (_jsonString.isEmpty()) {
            _jsonString += "{}";
        }
        int pos = _jsonString.toStdString().find("}");
        QString c = "{}" == _jsonString ? "" : ",";
        _jsonString.insert(pos, QString(c + "\"" + toString(T::_key) + "\":\"" + s + "\""));
    }

    QString getJsonString()
    {
        return _jsonString;
    }

private:
    QString _jsonString;

#endif // JSON_HPP
