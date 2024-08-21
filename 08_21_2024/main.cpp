#include <iostream>
#include "clock.h"

void anotherFunc(int &x);
int main()
{
    int x;
    anotherFunc(x);
    clockType clock;

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