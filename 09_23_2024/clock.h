#ifndef CLOCK_H
#define CLOCK_H

#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "clockExcept.h"

enum hourType
{
    TWELVE,
    TWENTYFOUR
};
enum amPmType
{
    AM,
    PM
};

const std::string hourToString[] = {"12 hour clock", "24 hour clock"};
const std::string amPmToString[] = {"AM", "PM"};
const hourType availableTypes[] = {TWELVE, TWENTYFOUR};
const amPmType timesOfDay[] = {AM, PM};

class clockType
{
public:
    // clockType();
    clockType(int h = 0, int m = 0, int s = 0, hourType = availableTypes[1], amPmType = timesOfDay[1]); // first parameter is hour, second is minute, third is second.
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void setClockType(hourType h);
    void setAmPm(amPmType a);
    std::string print() const;
    void incrementSecond();
    void incrementMinute();
    void incrementHour();

    bool operator==(const clockType &) const;
    bool operator!=(const clockType &) const;
    bool operator>(const clockType &) const;
    bool operator<(const clockType &) const;
    bool operator>=(const clockType &) const;
    bool operator<=(const clockType &) const;
    clockType operator+(const clockType &) const;
    clockType operator+(int minutesToAdd) const;
    clockType &operator+=(int minutesToAdd);
    const clockType &operator=(const clockType &);
    clockType operator++();
    clockType operator++(int);
    friend void two(const clockType &);
    friend clockType operator+(int minutesToAdd, const clockType &);
    friend std::ostream &operator<<(std::ostream &, const clockType &);

private:
    int hour;
    int minute;
    int second;
    hourType type;
    amPmType timeOfDay;
};

#endif