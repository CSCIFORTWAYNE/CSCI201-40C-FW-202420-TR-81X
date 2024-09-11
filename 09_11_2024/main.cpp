#include <iostream>
#include "clock.h"

int main()
{
    clockType clock1(1, 0, 0, TWELVE, PM);
    clockType clock2(13, 0, 0);
    clockType clock3(11, 0, 2);
    if (clock1 == clock2)
    {
        std::cout << "Clock1 and clock2 are the same." << std::endl;
    }
    if (clock1 != clock3)
    {
        std::cout << "Clock1 and clock3 are different." << std::endl;
    }

    clock1 = clock1 + 60 + 120;
    int x = 8;
    x + 7;

    return 0;
}