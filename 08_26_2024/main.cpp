#include "person.h"
#include "employee.h"
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
    return 0;
}