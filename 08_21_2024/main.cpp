#include <iostream>
#include "clock.h"

void anotherFunc(int &x);
int main()
{
    /*  int x;
     anotherFunc(x); */
    clockType clock(1, 50, 23);
    clockType clock2(11, 59, 00, TWELVE, AM);
    std::cout << clock2.printTime() << std::endl;
    clock2.incrementMinutes();
    std::cout << clock2.printTime() << std::endl;
    clock.setTime(13, 0, 0);
    clock2.incrementHours();
    std::cout << clock.printTime() << std::endl;
    std::cout << clock2.printTime() << std::endl;
    std::string same = clock.equalTime(clock2) ? "The clocks are equal" : "The clocks are different";
    std::cout << same << std::endl;
    clock2.setTimeOfDay(AM);
    same = clock.equalTime(clock2) ? "The clocks are equal" : "The clocks are different";
    std::cout << same << std::endl;
    clock2.incrementSeconds();
    same = clock.equalTime(clock2) ? "The clocks are equal" : "The clocks are different";
    std::cout << same << std::endl;

    // clockType theClocks[50];

    return 0;
}

void anotherFunc(int &x)
{
    static int y = 7;
    x = 7;
    for (int i = 0; i < 10; i++)
    {
        y++;
    }
}