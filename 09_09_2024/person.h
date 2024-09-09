#ifndef PERSON_H
#define PERSON_H
#include <string>
class person
{
public:
    person(std::string f, std::string l, std::string a = "", std::string p = "", std::string e = "");
    std::string getFname() const;
    std::string getLname() const;
    std::string getAddress() const;
    std::string getPhone() const;
    std::string getEmail() const;
    virtual std::string tostring() const;
    void setFname(std::string);
    void setLname(std::string);
    void setAddress(std::string);
    void setPhone(std::string);
    void setEmail(std::string);

protected:
    std::string fname;
    std::string lname;
    std::string address;
    std::string phone;
    std::string email;
};
#endif