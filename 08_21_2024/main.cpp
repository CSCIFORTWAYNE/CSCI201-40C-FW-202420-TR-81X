#include <iostream>
#include <limits>
#include "clock.h"
#include "drink.h"

void anotherFunc(int &x);
drink createDrink();
baseType getDrinkBase();
tempType getDrinkTemp();
sizeType getDrinkSize();
void getFlavors(flavType[], int &);
std::string getDairy();
void resetStream();
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
    drink d = createDrink();

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

drink createDrink()
{
    baseType base = getDrinkBase();
    tempType temp = getDrinkTemp();
    sizeType size = getDrinkSize();
    flavType flavs[10];
    int numF = 0;
    getFlavors(flavs, numF);
    std::string dairy = getDairy();
    drink newDrink(base, temp, size, flavs, numF, dairy);
    return newDrink;
}

baseType getDrinkBase()
{
    int baseInt;
    std::cout << "Please choose a drink base:" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << i + 1 << ": " << baseStr[i] << std::endl;
    }
    std::cin >> baseInt;
    while (!std::cin || baseInt < 1 || baseInt > 3)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "Please choose between 1 and 3." << std::endl;
        std::cin >> baseInt;
    }

    return bases[baseInt - 1];
}

tempType getDrinkTemp()
{
    int tempInt;
    std::cout << "Please choose a drink temperature:" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << i + 1 << ": " << tempStr[i] << std::endl;
    }
    std::cin >> tempInt;
    while (!std::cin || tempInt < 1 || tempInt > 3)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "Please choose between 1 and 3." << std::endl;
        std::cin >> tempInt;
    }

    return temps[tempInt - 1];
}

sizeType getDrinkSize()
{
    int sizeInt;
    std::cout << "Please choose a drink size:" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << i + 1 << ": " << sizeStr[i] << std::endl;
    }
    std::cin >> sizeInt;
    while (!std::cin || sizeInt < 1 || sizeInt > 3)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "Please choose between 1 and 3." << std::endl;
        std::cin >> sizeInt;
    }

    return sizes[sizeInt - 1];
}

void getFlavors(flavType f[], int &n)
{
    char yN = 'y';
    std::string flav;
    while (yN == 'y')
    {
        std::cout << "Please choose a flavor, available flavors ";
        std::cout << flavStr[0];
        for (int i = 1; i < 10; i++)
        {
            std::cout << ", " << flavStr[i];
        }
        std::cout << ", or enter none for no flavors: ";
        getline(std::cin >> std::ws, flav);
        std::transform(flav.begin(), flav.end(), flav.begin(), ::tolower);
        if (flav == "none")
        {
            return;
        }
        for (int i = 0; i < 10; i++)
        {
            std::string tempFlav = flavStr[i];
            std::transform(tempFlav.begin(), tempFlav.end(), tempFlav.begin(), ::tolower);
            if (tempFlav == flav)
            {
                f[n] = flavs[i];
                n++;
                break;
            }
        }
        std::cout << "Do you want to add another flavor? ";
        std::cin >> yN;
        yN = tolower(yN);
    }
}

std::string getDairy()
{
    return std::string();
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "You did not enter a number." << std::endl;
}
