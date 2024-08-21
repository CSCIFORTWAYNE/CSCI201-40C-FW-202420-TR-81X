#include <string>
#include <iostream>

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
    clockType();
    clockType(int, int, int);
    void setTime(int, int, int);
    void getTime(int &, int &, int &) const;
    int getHour() const;
    std::string printTime() const;
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