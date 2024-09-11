#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

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
    std::string printTime() const;
    void setTime(int, int, int, todType = PM);
    void setHour(int);
    void setMin(int);
    void setSec(int);
    void setTimeOfDay(todType);
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool operator==(const clockType &rightClock) const;
    bool operator!=(const clockType &rightClock) const;
    clockType &operator+(int secondsToAdd);
    friend clockType &operator+(int secondsToAdd, clockType &rightClock);

private:
    bool equalTime(const clockType &otherClock) const;
    int hr;
    int min;
    int sec;
    todType tod;
    cType type;
};