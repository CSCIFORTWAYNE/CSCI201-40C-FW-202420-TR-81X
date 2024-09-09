#include "person.h"

person::person(std::string f, std::string l, std::string a, std::string p, std::string e)
{
    fname = f;
    lname = l;
    address = a;
    phone = p;
    email = e;
}

std::string person::tostring() const
{
    std::string output;
    output = "First name: " + fname + "\n";
    output += "Last name: " + lname + "\n";
    if (!address.empty())
    {
        output += "Address: " + address + "\n";
    }
    if (!phone.empty())
    {
        output += "Phone: " + phone + "\n";
    }
    if (!email.empty())
    {
        output += "Email: " + email + "\n";
    }
    return output;
}

std::string person::getFname() const
{
    return fname;
}
std::string person::getLname() const
{
    return lname;
}
std::string person::getAddress() const
{
    return address;
}
std::string person::getPhone() const
{
    return phone;
}
std::string person::getEmail() const
{
    return email;
}