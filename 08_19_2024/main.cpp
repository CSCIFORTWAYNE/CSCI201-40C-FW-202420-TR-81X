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

struct cardType
{
    std::string suit;
    rankType rank;
};

int main()
{
    cardType myCard;
    myCard.suit = "SPADES";
    myCard.rank = ACE;
    // std::cout << myCard;
    // std::cin >> myCard;

    return 0;
}