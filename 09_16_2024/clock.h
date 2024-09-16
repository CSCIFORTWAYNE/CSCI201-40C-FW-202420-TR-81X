#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>

enum cType
{
    TWELVE,
    TWENTYFOUR
};
enum todType
{
    AM,
    PM
};

class clockType
{
public:
    /*  clockType();*/
    clockType(int, int, int, cType = TWENTYFOUR, todType = PM);
    void getTime(int &, int &, int &) const;
    int getHour() const;
    int getMin() const;
    int getSec() const;
    cType getClockType() const;
    todType getTimeOfDay() const;

    void setTime(int, int, int, todType = PM);
    void setHour(int);
    void setMin(int);
    void setSec(int);
    void setTimeOfDay(todType);
    void incrementMinutes();
    void incrementHours();
    bool operator==(const clockType &rightClock) const;
    bool operator!=(const clockType &rightClock) const;
    clockType &operator+(int secondsToAdd);
    const clockType &operator=(const clockType &rightClock);
    clockType operator++();
    clockType operator++(int);
    friend clockType &operator+(int secondsToAdd, clockType &rightClock);
    friend std::ostream &operator<<(std::ostream &, const clockType &rightClock);
    friend std::istream &operator>>(std::istream &, clockType &rightClock);

private:
    void incrementSeconds();
    std::string printTime() const;
    bool equalTime(const clockType &otherClock) const;
    void setClockType(cType);
    int hr;
    int min;
    int sec;
    todType tod;
    cType type;
};