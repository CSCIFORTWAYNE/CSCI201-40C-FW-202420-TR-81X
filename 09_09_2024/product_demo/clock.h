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
    bool equalTime(const clockType &otherClock) const;

private:
    int hr;
    int min;
    int sec;
    todType tod;
    cType type;
};