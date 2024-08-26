#include "person.h"
#include "employee.h"
#include "donut.h"
#include <iostream>

// add data entry to main to get employee information
// add a comment with your test input
// create the employee
// call the to string
int main()
{
    person p("john", "doe");
    employee e("jane", "doe", "123-45-6789", "2024-02-26");

    std::cout << p.tostring() << std::endl;
    std::cout << e.tostring() << std::endl;

    std::cout << "Please pick a topping: " << std::endl;
    for (int i = 0; i < NUM_TOP; i++)
    {
        std::cout << i + 1 << ": " << toppingStr[i] << std::endl;
    }
    int topInt;
    std::cin >> topInt;
    while (!std::cin || topInt <= 0 || topInt > NUM_TOP)
    {
        if (!std::cin)
        {
            // reset stream here
        }
        std::cout << "Please choose a number from the list" << std::endl;
        std::cin >> topInt;
    }
    toppingType top = toppings[topInt - 1];
    std::cout << "You chose " << toppingStr[top] << std::endl;
    return 0;
}