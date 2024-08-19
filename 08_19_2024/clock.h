#include <string>
#include <iostream>

class clockType
{
public:
    clockType();
    clockType(int, int, int);
    void setTime(int, int, int);
    void getTime(int &, int &, int &) const;
    std::string printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType &otherClock) const;

private:
    int hr;
    int min;
    int sec;
};