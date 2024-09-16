#include <iostream>
#include <cstdlib>
#include "clock.h"

template <class t>
t findLargest(t list[], int numItems);

int main()
{
    int list[10];
    clockType **clockList = new clockType *[10];

    for (int i = 0; i < 10; i++)
    {
        list[i] = rand() % 1000 + 1;
        cType ct = static_cast<cType>(rand() % 2);
        int hours;
        if (ct == TWELVE)
        {
            hours = rand() % 12 + 1;
        }
        else
        {
            hours = rand() % 24;
        }

        clockList[i] = new clockType(hours, rand() % 60, rand() % 60, ct);
    }
    clockType *largestClock = findLargest(clockList, 10);
    int largestInt = findLargest(list, 10);

    for (int i = 0; i < 10; i++)
    {
        delete clockList[i];
    }
    delete[] clockList;

    return 0;
}

template <class t>
t findLargest(t list[], int numItems)
{
    int largestPos = 0;
    for (int i = 1; i < numItems; i++)
    {
        if (list[i] > list[largestPos])
        {
            largestPos = i;
        }
    }
    return list[largestPos];
}
