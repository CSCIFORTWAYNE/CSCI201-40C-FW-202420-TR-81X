#include "employee.h"

std::string employee::tostring() const
{
    std::string output;
    output = "Employee First Name: " + getFname();
    return;
}