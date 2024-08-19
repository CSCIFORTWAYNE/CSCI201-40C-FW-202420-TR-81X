#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

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
    cardType myCard;
    myCard.setSuit("SPADES");
    // myCard.rank = ACE;
    //  std::cout << myCard;
    //  std::cin >> myCard;

    return 0;
}