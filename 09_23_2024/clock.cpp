#include "clock.h"

void clockType::setHour(int h)
{
    if (type == TWENTYFOUR)
    {
        if (h >= 0 && h <= 23)
        {
            hour = h;
        }
        else
        {
            throw invalid_hour("The hour is invalid. Valid values are between 0 and 23.");
        }
    }
    else
    {
        if (h >= 1 && h <= 12)
        {
            hour = h;
        }
        else
        {
            throw invalid_hour("The hour is invalid. Valid values are between 1 and 12.");
        }
    }
}

clockType::clockType(int h, int m, int s, hourType t, amPmType tod)
{
    try
    {
        type = t;
        timeOfDay = tod;
        setHour(h);
        setMinute(m);
        setSecond(s);
    }
    catch (invalid_hour e)
    {
        std::string msg = e.what();
        msg += "\nclockType constructor:35";
        throw invalid_hour(msg);
    }
    catch (invalid_min e)
    {
        std::string msg = e.what();
        msg += "\nclockType constructor:36";
        throw invalid_min(msg);
    }
    catch (invalid_sec e)
    {
        std::string msg = e.what();
        msg += "\nclockType constructor:37";
        throw invalid_sec(msg);
    }
}

void clockType::setMinute(int m)
{
    if (m >= 0 && m <= 59)
    {
        minute = m;
    }
    else
    {
        throw invalid_min("The minute is invalid. Valid values are between 0 and 59.");
    }
}

void clockType::setSecond(int s)
{
    if (s >= 0 && s <= 59)
    {
        second = s;
    }
    else
    {
        throw invalid_sec("The second is invalid. Valid values are between 0 and 59.");
    }
}

void clockType::setClockType(hourType h)
{
    type = h;
}

void clockType::setAmPm(amPmType a)
{
    timeOfDay = a;
}

int clockType::getHour() const
{
    return hour;
}

int clockType::getMinute() const
{
    return minute;
}

int clockType::getSecond() const
{
    return second;
}

std::string clockType::print() const
{
    std::ostringstream out;
    out << std::setfill('0');
    out << std::setw(2) << hour << ":";
    out << std::setw(2) << minute << ":";
    out << std::setw(2) << second;
    if (type == TWELVE)
    {
        out << " " << amPmToString[timeOfDay];
    }
    else
    {
        out << std::endl;
        out << hourToString[type] << std::endl;
    }
    return out.str();
}

bool clockType::operator==(const clockType &otherClock) const
{

    int cmpHour = this->hour;
    int cmpOthHour = otherClock.hour;
    if (this->type == TWELVE)
    {
        if (this->timeOfDay == PM && this->hour != 12)
        {
            cmpHour = (this->hour + 12) % 24;
        }
    }
    if (otherClock.type == TWELVE)
    {
        if (this->timeOfDay == PM && otherClock.hour != 12)
        {
            cmpOthHour = (otherClock.hour + 12) % 24;
        }
    }
    return cmpHour == cmpOthHour && this->minute == otherClock.minute;
}

bool clockType::operator!=(const clockType &otherClock) const
{
    return !(*this == otherClock);
}

bool clockType::operator>(const clockType &otherClock) const
{
    bool greater;

    int cmpHour = this->hour;
    int cmpOthHour = otherClock.hour;
    if (this->type == TWELVE)
    {
        if (this->timeOfDay == PM && this->hour != 12)
        {
            cmpHour = (this->hour + 12) % 24;
        }
    }
    if (otherClock.type == TWELVE)
    {
        if (this->timeOfDay == PM && otherClock.hour != 12)
        {
            cmpOthHour = (otherClock.hour + 12) % 24;
        }
    }
    if (cmpHour == cmpOthHour)
    {
        if (this->minute == otherClock.minute)
        {
            if (this->second == otherClock.second)
            {
                greater = false;
            }
            else if (this->second > otherClock.second)
            {
                greater = true;
            }
            else
            {
                greater = false;
            }
        }
        else if (this->minute > otherClock.minute)
        {
            greater = true;
        }
        else
        {
            greater = false;
        }
    }
    else if (cmpHour > cmpOthHour)
    {
        greater = true;
    }
    else
    {
        greater = false;
    }
    return greater;
}

bool clockType::operator<(const clockType &otherClock) const
{

    bool less;

    int cmpHour = this->hour;
    int cmpOthHour = otherClock.hour;
    if (this->type == TWELVE)
    {
        if (this->timeOfDay == PM && this->hour != 12)
        {
            cmpHour = (this->hour + 12) % 24;
        }
    }
    if (otherClock.type == TWELVE)
    {
        if (this->timeOfDay == PM && otherClock.hour != 12)
        {
            cmpOthHour = (otherClock.hour + 12) % 24;
        }
    }
    if (cmpHour == cmpOthHour)
    {
        if (this->minute == otherClock.minute)
        {
            if (this->second == otherClock.second)
            {
                less = false;
            }
            else if (this->second < otherClock.second)
            {
                less = true;
            }
            else
            {
                less = false;
            }
        }
        else if (this->minute < otherClock.minute)
        {
            less = true;
        }
        else
        {
            less = false;
        }
    }
    else if (cmpHour < cmpOthHour)
    {
        less = true;
    }
    else
    {
        less = false;
    }
    return less;
}

bool clockType::operator>=(const clockType &otherClock) const
{
    return *this > otherClock || *this == otherClock;
}

bool clockType::operator<=(const clockType &otherClock) const
{
    return *this < otherClock || *this == otherClock;
}

void clockType::incrementSecond()
{
    second++;
    if (second > 59)
    {
        second = 0;
        incrementMinute();
    }
}

void clockType::incrementMinute()
{
    minute++;
    if (minute > 59)
    {
        minute = 0;
        incrementHour();
    }
}

void clockType::incrementHour()
{
    hour++;
    if (type == TWELVE)
    {
        if (hour == 12)
        {
            timeOfDay == PM ? timeOfDay = AM : timeOfDay = PM; // if timeofday is pm set to am otherwise set to pm.
        }
        if (hour > 12)
        {
            hour = 1;
            // timeOfDay == PM ? timeOfDay = AM : timeOfDay = PM; // if timeofday is pm set to am otherwise set to pm.
        }
    }
    else
    {
        if (hour > 23)
            hour = 0;
    }
}

clockType clockType::operator+(const clockType &otherClock) const
{
    int standHour = this->hour;
    int standOthHour = otherClock.hour;
    if (this->type == TWELVE)
    {
        if (this->timeOfDay == PM && this->hour != 12)
        {
            standHour = (this->hour + 12) % 24;
        }
    }
    if (otherClock.type == TWELVE)
    {
        if (this->timeOfDay == PM)
        {
            standHour = (otherClock.hour + 12) % 24;
        }
    }
    int newSecond = this->second + otherClock.second;
    int addMin = newSecond / 60;
    newSecond = newSecond % 60;
    int newMinute = this->minute + otherClock.minute + addMin;
    int addHour = newMinute / 60;
    newMinute = newMinute % 60;
    int newHour = standHour + standOthHour + addHour;
    newHour = newHour % 24;
    return clockType(newHour, newMinute, newSecond, TWENTYFOUR);
}

clockType clockType::operator+(int minutesToAdd) const
{
    clockType c(0, minutesToAdd, 0, TWENTYFOUR);
    return *this + c;
}

clockType &clockType::operator+=(int minutesToAdd)
{
    int standHour = this->hour;
    if (this->type == TWELVE)
    {
        if (this->timeOfDay == PM && this->hour != 12)
        {
            standHour = (this->hour + 12) % 24;
        }
    }

    int newMinute = this->minute + minutesToAdd;
    int addHour = newMinute / 60;
    newMinute = newMinute % 60;
    int newHour = standHour + addHour;
    newHour = newHour % 24;
    this->minute = newMinute;
    if (this->type == TWELVE && newHour > 12)
    {
        this->hour = newHour - 12;
        this->timeOfDay = PM;
    }
    else if (this->type == TWELVE && newHour == 0)
    {
        this->hour = 12;
        this->timeOfDay == AM;
    }
    else if (this->type == TWELVE && newHour != 12)
    {
        this->timeOfDay = AM;
        this->hour = newHour;
    }
    else if (this->type == TWELVE && newHour == 12)
    {
        this->timeOfDay = PM;
    }

    else
    {
        this->hour = newHour;
    }
    return *this;
}

void two(const clockType &theClock)
{
    theClock.hour;
    theClock.minute;
}

std::ostream &operator<<(std::ostream &out, const clockType &c)
{
    out << c.print();

    return out;
}

clockType operator+(int minutesToAdd, const clockType &theClock)
{
    return theClock + minutesToAdd;
}

const clockType &clockType::operator=(const clockType &cpyClock)
{
    if (this != &cpyClock)
    {
        this->hour = cpyClock.hour;
        this->minute = cpyClock.minute;
        this->second = cpyClock.second;
        this->timeOfDay = cpyClock.timeOfDay;
        this->type = cpyClock.type;
    }
    return *this;
}

clockType clockType::operator++()
{
    this->incrementSecond();
    return *this;
}

clockType clockType::operator++(int)
{
    clockType temp(*this);
    this->incrementSecond();
    return temp;
}
