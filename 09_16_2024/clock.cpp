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

bool clockType::operator==(const clockType &rightClock) const
{
    return this->equalTime(rightClock);
}

bool clockType::operator!=(const clockType &rightClock) const
{
    return !(*this == rightClock);
}

clockType &clockType::operator+(int secondsToAdd)
{
    // clockType c(*this);
    for (int i = 0; i < secondsToAdd; i++)
    {
        incrementSeconds();
    }
    return *this;
}

void clockType::setClockType(cType type)
{
    this->type = type;
}

clockType &operator+(int secondsToAdd, clockType &rightClock)
{
    return rightClock + secondsToAdd;
}

std::ostream &operator<<(std::ostream &out, const clockType &rightClock)
{
    out << rightClock.printTime();
    return out;
}

std::istream &operator>>(std::istream &in, clockType &rightClock)
{
    std::cin >> std::ws;
    std::string clockStr;
    std::getline(std::cin, clockStr);
    std::istringstream inStr(clockStr);
    inStr >> rightClock.hr;
    char colon;
    inStr >> colon;
    inStr >> rightClock.min;
    inStr >> colon;
    inStr >> rightClock.sec;
    inStr.get();
    if (!inStr || inStr.eof())
    {
        rightClock.setClockType(TWENTYFOUR);
        return in;
    }
    else
    {
        rightClock.setClockType(TWELVE);
        std::string tod;
        inStr >> tod;
        std::transform(tod.begin(), tod.end(), tod.begin(), ::toupper);
        if (tod == "AM")
        {
            rightClock.setTimeOfDay(AM);
        }
        else if (tod == "PM")
        {
            rightClock.setTimeOfDay(PM);
        }
        else
        {
            rightClock.setClockType(TWENTYFOUR);
        }
    }
    return in;
}
const clockType &clockType::operator=(const clockType &rightClock)
{
    this->hr = rightClock.hr;
    this->min = rightClock.min;
    this->sec = rightClock.sec;
    this->tod = rightClock.tod;
    this->type = rightClock.type;
    return *this;
}

clockType clockType::operator++()
{
    incrementSeconds();
    return *this;
}

clockType clockType::operator++(int)
{
    clockType temp = *this;
    this->incrementSeconds();
    return temp;
}

bool clockType::operator>(const clockType &rightClock) const
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
    if (rightClock.type == TWELVE)
    {
        if (rightClock.tod == AM && rightClock.hr != 12)
        {
            cmpOH = rightClock.hr;
        }
        else if (rightClock.tod == AM && rightClock.hr == 12)
        {
            cmpOH = 0;
        }
        else if (rightClock.hr == 12)
        {
            cmpOH = rightClock.hr;
        }
        else
        {
            cmpOH = rightClock.hr + 12;
        }
    }
    else
    {
        cmpOH = rightClock.hr;
    }
    bool greater = false;
    if (cmpH > cmpOH)
    {
        greater = true;
    }
    else if (cmpH == cmpOH)
    {
        if (this->min > rightClock.min)
        {
            greater = true;
        }
        else if (this->min == rightClock.min)
        {
            if (this->sec > rightClock.sec)
            {
                greater = true;
            }
        }
    }
    return greater;
}
