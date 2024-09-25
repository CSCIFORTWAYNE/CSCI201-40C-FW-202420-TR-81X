#include <iostream>
#include <string>
#include <exception>
#include <limits>
#include "clock.h"
#include "clockExcept.h"

int getPositiveInt(std::string prompt);
void resetStream();

// lecture activity create a custom exception class for invalid_dairy strings. Modify the setDairy in the drink class so it throws your new exception class when the diary string doesn't match one we have a price for.

int main()
{
    bool validHours = false;
    bool validMin = false;
    bool validSec = false;
    int hour, min, sec;
    clockType *myClock;
    while (!validHours || !validMin || !validSec)
    {
        try
        {
            if (!validHours)
            {
                hour = getPositiveInt("Enter the hours for the clock: ");
                validHours = true;
            }
            if (!validMin)
            {
                min = getPositiveInt("Enter the minutes for the clock: ");
                validMin = true;
            }
            if (!validSec)
            {
                sec = getPositiveInt("Enter the seconds for the clock: ");
                validSec = true;
            }
            myClock = new clockType(hour, min, sec);
                }
        catch (std::ios_base::failure e)
        {
            std::cout << e.what() << std::endl;
            resetStream();
        }
        catch (std::domain_error e)
        {
            std::cout << e.what() << std::endl;
        }
        catch (invalid_hour e)
        {
            std::cout << e.what() << std::endl;
            validHours = false;
        }
        catch (invalid_min e)
        {
            std::cout << e.what() << std::endl;
            validMin = false;
        }
        catch (invalid_sec e)
        {
            std::cout << e.what() << std::endl;
            validSec = false;
        }
    }

    std::cout << *myClock << std::endl;
    /* int x;
    // std::cin.exceptions(std::istream::badbit | std::istream::failbit);
    bool isValid = false;
    while (!isValid)
    {
        try
        {
            x = getPositiveInt("Enter a positive number: ");
            isValid = true;
        }
        catch (std::ios_base::failure e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "There was an input error." << std::endl;
            resetStream();
        }
        catch (std::domain_error e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    try
    {
        clockType c(12, x, x);
    }

    catch (invalid_hour e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (std::invalid_argument e)
    {
        std::cerr << "invalid argument caught" << std::endl;
        std::cerr << e.what() << '\n';
    } */
    return 0;
}

int getPositiveInt(std::string prompt)
{
    int x;
    std::cout << prompt;
    std::cin >> x;
    std::cout << std::endl;
    if (!std::cin)
    {
        throw std::ios_base::failure("There was an error getting the positive integer. The user most likely entered a character instead.");
    }
    else if (x <= 0)
    {
        throw std::domain_error("The number entered is less than 0");
    }
    return x;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
