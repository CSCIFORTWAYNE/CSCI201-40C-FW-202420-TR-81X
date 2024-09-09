#include "employee.h"

employee::employee(std::string f, std::string l, std::string s, std::string h, double sal, std::string a, std::string p, std::string e) : person(f, l, a, p, e)
{
    ssn = s;
    hireDate = h;
    setSalary(sal);
}

double employee::getSalary() const
{
    return salary;
}

std::string employee::getHireDate() const
{
    return hireDate;
}

void employee::setSalary(double sal)
{
    if (sal < 6000)
    {
        salary = 6000;
    }
    else
    {
        salary = sal;
    }
}

std::string employee::tostring() const
{
    std::string output;
    output = person::tostring();
    output += "Salary: " + std::to_string(salary) + "\n";
    output += "Hire Date: " + hireDate + "\n";
    return output;
}

void example()
{
}