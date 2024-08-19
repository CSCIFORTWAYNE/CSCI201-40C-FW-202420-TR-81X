#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include "clock.h"

enum rankType
{
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

class cardType
{
public:
    std::string getSuit();
    void setSuit(std::string s);

private:
    std::string suit;
    rankType rank;
};

int main()
{
    clockType myClock;
    clockType classClock(16, 16, 34);
    std::cout << myClock.printTime() << std::endl;
    std::cout << classClock.printTime() << std::endl;
    // cardType myCard;
    // myCard.setSuit("SPADES");
    //  myCard.rank = ACE;
    //   std::cout << myCard;
    //   std::cin >> myCard;

    return 0;
}