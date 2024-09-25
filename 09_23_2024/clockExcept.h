#ifndef CLOCKE_H
#define CLOCKE_H
#include <stdexcept>
#include <string>

class invalid_hour : public std::invalid_argument
{
public:
    invalid_hour(std::string msg = "Invalid hour exception");
};
class invalid_min : public std::invalid_argument
{
public:
    invalid_min(std::string msg = "Invalid min exception");
};
class invalid_sec : public std::invalid_argument
{
public:
    invalid_sec(std::string msg = "Invalid second exception");
};

#endif