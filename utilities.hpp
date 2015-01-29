#ifndef UTILITIES_HPP
#define UTILITIES_HPP

class utilities
{
public:
    static QString changeDateFormat(const QString& date)
    {
        QStringList dl = date.split("\\");
        return dl[2] + "-" + dl[1] + "-" + dl[0];
    }
};

#endif // UTILITIES_HPP
