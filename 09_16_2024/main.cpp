#include <iostream>
#include <cstdlib>
#include <vector>
#include <array>
#include <random>
#include "clock.h"

template <class t>
t findLargest(const std::vector<t> &, int numItems);

int main()
{
    // int list[10];
    std::vector<int> list(10);
    // clockType **clockList = new clockType *[10];
    // std::array<clockType, 10> clockArray(); This syntax may be incorrect
    std::vector<clockType> clockList;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 1000);
    std::uniform_int_distribution<int> distributionCType(TWELVE, TWENTYFOUR);
    std::uniform_int_distribution<int> distribute12Hr(1, 12);
    std::uniform_int_distribution<int> distribute24Hr(0, 23);
    std::uniform_int_distribution<int> distributeMin(0, 59);

    for (int i = 0; i < 10; i++)
    {
        // list[i] = rand() % 1000 + 1;
        list[i] = distribution(generator);
        cType ct = static_cast<cType>(distributionCType(generator)); // static_cast<cType>(rand() % 2);
        int hours;
        if (ct == TWELVE)
        {
            hours = distribute12Hr(generator); // rand() % 12 + 1;
        }
        else
        {
            hours = distribute24Hr(generator); // rand() % 24;
        }

        clockList.push_back(clockType(hours, distributeMin(generator), distributeMin(generator), ct));
    }
    clockType largestClock = findLargest(clockList, 10);
    int largestInt = findLargest(list, 10);

    for (std::vector<int>::iterator it = list.begin(); it != list.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    /*  for (int i = 0; i < 10; i++)
     {
         delete clockList[i];
     }
     delete[] clockList; */

    return 0;
}

template <class t>
t findLargest(const std::vector<t> &list, int numItems)
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
