#include "clock.h"

void clockType::setTime(int h, int m, int s, todType t)
{
    setHour(h);
    setMin(m);
    setSec(s);
    setTimeOfDay(t);
}

void clockType::getTime(int &h, int &m, int &s) const
{
    h = hr;
    m = min;
    s = sec;
}

std::string clockType::printTime() const
{
    std::ostringstream output;
    output << std::setfill('0');
    output << std::setw(2) << hr << ":";
    output << std::setw(2) << min << ":";
    output << std::setw(2) << sec;
    if (type == TWELVE)
    {
        if (tod == AM)
        {
            output << " AM";
        }
        else
        {
            output << " PM";
        }
    }
    // output = std::to_string(hr) + ":" + std::to_string(min) + ":" + std::to_string(sec);
    return output.str();
}

void clockType::incrementSeconds()
{
    sec++;
    if (sec == 60)
    {
        sec = 0;
        incrementMinutes();
    }
}

void clockType::incrementMinutes()
{
    min++;
    if (min == 60)
    {
        min = 0;
        incrementHours();
    }
}

void clockType::incrementHours()
{
    hr++;
    if (type == TWELVE)
    {
        if (hr == 13)
        {
            hr = 1;
        }
        else if (hr == 12)
        {
            setTimeOfDay(static_cast<todType>(!tod));
            /* if(tod == PM)
            {
                setTimeOfDay(AM);
            }
            else
            {
                setTimeOfDay(PM);
            } */
        }
    }
    else
    {
        if (hr == 24)
        {
            hr = 0;
        }
    }
}

bool clockType::equalTime(const clockType &otherClock) const
{
    bool eq;
    int cmpH;
    int cmpOH;
    if (type == TWELVE)
    {
        if (tod == AM && hr != 12)
        {
            cmpH = hr;
        }
        else if (tod == AM && hr == 12)
        {
            cmpH = 0;
        }
        else if (hr == 12)
        {
            cmpH = hr;
        }
        else
        {
            cmpH = hr + 12;
        }
    }
    else
    {
        cmpH = hr;
    }
    if (otherClock.type == TWELVE)
    {
        if (otherClock.tod == AM && otherClock.hr != 12)
        {
            cmpOH = otherClock.hr;
        }
        else if (otherClock.tod == AM && otherClock.hr == 12)
        {
            cmpOH = 0;
        }
        else if (otherClock.hr == 12)
        {
            cmpOH = otherClock.hr;
        }
        else
        {
            cmpOH = otherClock.hr + 12;
        }
    }
    else
    {
        cmpOH = otherClock.hr;
    }
    eq = cmpH == cmpOH && min == otherClock.min && sec == otherClock.sec;

    return eq;
}

/* clockType::clockType()
{
    hr = 0;
    min = 0;
    sec = 0;
}*/

clockType::clockType(int h, int m, int s, cType t, todType td)
{
    type = t;
    setTime(h, m, s, td);
}

int clockType::getHour() const
{

    return hr;
}

int clockType::getMin() const
{
    return min;
}

int clockType::getSec() const
{
    return sec;
}

cType clockType::getClockType() const
{
    return type;
}

todType clockType::getTimeOfDay() const
{
    return tod;
}

void clockType::setHour(int h)
{
    if (type == TWELVE)
    {
        if (h >= 1 && h <= 12)
        {
            hr = h;
        }
        else
        {
            std::cout << "The hour supplied is invalid. Valid hours are between 1 and 12. The hour will not be changed." << std::endl;
        }
    }
    else
    {
        if (h >= 0 && h <= 23)
        {
            hr = h;
        }
        else
        {
            std::cout << "The hour supplied is invalid. Valid hours are between 0 and 23. The hour will not be changed." << std::endl;
        }
    }
}

void clockType::setMin(int m)
{
    if (m >= 0 && m <= 59)
    {
        min = m;
    }
    else
    {
        std::cout << "The minutes are invalid. Valid minutes are between 0 and 59. The minutes will not be changed." << std::endl;
        return;
    }
}

void clockType::setSec(int s)
{
    if (s >= 0 && s <= 59)
    {
        sec = s;
    }
    else
    {
        std::cout << "The seconds are invalid. Valid seconds are between 0 and 59. The seconds will not be changed." << std::endl;
        return;
    }
}

void clockType::setTimeOfDay(todType t)
{
    tod = t;
}