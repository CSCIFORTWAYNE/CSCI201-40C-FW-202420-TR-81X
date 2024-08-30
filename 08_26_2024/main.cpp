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
    //noah gutie, 345343456, 01/07/2022, 32000, 1234 livehere dr, 574-222-1234, noahgutie@gmail.com
    //constructors for variables to hold responses
    std::string fn;
    std::string ln;
    std::string ss;
    std::string hd;
    std::string wage;
    std::string addy;
    std::string pn;
    std::string em;
    
    //prompts and scans of responses
    std::cout << "Enter the first name of the new employee: " << std::endl;
	std::getline(std::cin, fn);
    std::cout << "Enter the last name of the new employee: " << std::endl;
	std::getline(std::cin, ln);
    std::cout << "Enter the ssn of the new employee: " << std::endl;
	std::getline(std::cin, ss);
    std::cout << "Enter the hire date of the new employee: " << std::endl;
	std::getline(std::cin, hd);
    std::cout << "Enter the salary of the new employee: " << std::endl;
	std::getline(std::cin, wage);
    std::cout << "Enter the address of the new employee: " << std::endl;
	std::getline(std::cin, addy);
    std::cout << "Enter the phone number of the new employee: " << std::endl;
	std::getline(std::cin, pn);
    std::cout << "Enter the email of the new employee: " << std::endl;
	std::getline(std::cin, em);
    

    //makes new employee using responses
    employee nt(fn, ln, ss, hd, wage, addy, pn, em);

    //prints results
    std::cout << nt.tostring() << std::endl;
    
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
