#include "clock.h"

void clockType::setTime(int h, int m, int s)
{
    if (h >= 0 && h <= 23)
    {
        hr = h;
    }
    else
    {
        std::cout << "The hour is invalid. The clock will not be changed." << std::endl;
        return;
    }
    if (m >= 0 && m <= 59)
    {
        min = m;
    }
    else
    {
        std::cout << "The minute is invalid. The clock will not be changed." << std::endl;
        return;
    }
    if (s >= 0 && s <= 59)
    {
        sec = s;
    }
    else
    {
        std::cout << "The second is invalid. The clock will not be changed." << std::endl;
        return;
    }
}

void clockType::getTime(int &h, int &m, int &s) const
{
    h = hr;
    m = min;
    s = sec;
}

std::string clockType::printTime() const
{
    std::string output;
    output = std::to_string(hr) + ":" + std::to_string(min) + ":" + std::to_string(sec);
    return output;
}

void clockType::incrementSeconds()
{
    sec++;
    if (sec == 60)
    {
        sec = 0;
    }
}

void clockType::incrementMinutes()
{
    min++;
    if (min == 60)
    {
        min = 0;
    }
}

void clockType::incrementHours()
{
    hr++;
    if (hr == 24)
    {
        hr = 0;
    }
}

bool clockType::equalTime(const clockType &otherClock) const
{

    return otherClock.hr == hr && otherClock.min == min && otherClock.sec == sec;
}

clockType::clockType()
{
    hr = 0;
    min = 0;
    sec = 0;
}

clockType::clockType(int h, int m, int s)
{
    setTime(h, m, s);
}

int clockType::getHour() const
{

    return hr;
}

void clockType::setTod(std::string t)
{
    tod = t;
}
