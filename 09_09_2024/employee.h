#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "person.h"
class employee : public person
{
public:
    employee(std::string f, std::string l, std::string s, std::string h, double sal = 6000, std::string a = "", std::string p = "", std::string e = "");
    double getSalary() const;
    std::string getHireDate() const;
    void setSalary(double sal);
    std::string tostring() const;
    void example();

private:
    double salary;
    std::string ssn;
    std::string hireDate;
};
#endif