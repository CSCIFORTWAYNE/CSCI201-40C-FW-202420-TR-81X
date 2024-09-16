#include <iostream>
#include <cstdlib>
#include <vector>
#include <array>
#include <random>
#include "clock.h"
#include "product.h"

// add static maps for the rest of the drink enums
// add static maps to the clock class for the enums

template <class t>
t findLargest(const std::vector<t> &, int numItems);

bool isValidDairy(std::string dairy);

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
    std::string drinkBaseStr;
    std::cout << "Enter the drink base: ";
    std::cin >> drinkBaseStr;
    std::transform(drinkBaseStr.begin(), drinkBaseStr.end(), drinkBaseStr.begin(), ::tolower);
    while (!drink::stringToBase.count(drinkBaseStr))
    {
        std::cout << "That is not a valid drink base. Please choose from the following:" << std::endl;
        std::map<baseType, std::string>::iterator it = drink::baseToString.begin();
        for (it; it != drink::baseToString.end(); it++)
        {
            std::cout << it->second << std::endl;
        }
        std::cin >> drinkBaseStr;
        std::transform(drinkBaseStr.begin(), drinkBaseStr.end(), drinkBaseStr.begin(), ::tolower);
    }
    baseType b = drink::stringToBase.at(drinkBaseStr);
    std::string dairyStr;
    std::cout << "Enter the dairy for the drink: ";
    std::getline(std::cin >> std::ws, dairyStr);
    std::string dairyCpy = dairyStr;
    std::transform(dairyStr.begin(), dairyStr.end(), dairyCpy.begin(), ::tolower);
    dairyCpy[0] = toupper(dairyCpy[0]);
    int i = dairyCpy.find_first_of(' ');
    dairyCpy[i + 1] = toupper(dairyCpy[i + 1]);
    while (!isValidDairy(dairyStr))
    {
        std::cout << "That is not a valid dairy option. Please choose from the following:" << std::endl;
        std::set<std::string>::iterator it = drink::dairyOptions.begin();
        for (it; it != drink::dairyOptions.end(); it++)
        {
            std::cout << *it << std::endl;
        }
        std::getline(std::cin >> std::ws, dairyStr);
        dairyCpy = dairyStr;
        std::transform(dairyStr.begin(), dairyStr.end(), dairyCpy.begin(), ::tolower);
        dairyCpy[0] = toupper(dairyCpy[0]);
        int i = dairyCpy.find_first_of(' ');
        dairyCpy[i + 1] = toupper(dairyCpy[i + 1]);
    }
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

bool isValidDairy(std::string dairy)
{

    std::transform(dairy.begin(), dairy.end(), dairy.begin(), ::tolower);
    std::set<std::string>::iterator it = drink::dairyOptions.begin();
    for (it; it != drink::dairyOptions.end(); it++)
    {
        std::string optionCpy = *it;
        std::transform(optionCpy.begin(), optionCpy.end(), optionCpy.begin(), ::tolower);
        if (dairy == optionCpy)
            return true;
    }
    return false;
}
