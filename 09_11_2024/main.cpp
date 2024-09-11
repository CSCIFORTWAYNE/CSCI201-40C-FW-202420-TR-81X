#include <iostream>
#include "clock.h"

// add >, >=, <, <= to the clock class
// add pre and post -- to the clock class;

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

    clock1 = clock1++ + 60 + 120;
    // clock1 = 60 + clock2;
    // clock1 = clock2 + 60;
    int x = 8;
    x = x++ + 7;
    7 + x;
    x++;
    std::cin >> x;
    std::cout << clock1 << std::endl;
    std::cin >> clock3;
    std::cout << clock3 << std::endl;

    int y = 20;
    int z = 23;
    x = (y = z);
    clock1 = clock2 = clock3;

    return 0;
}