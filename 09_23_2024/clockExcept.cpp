#include "clockExcept.h"

invalid_hour::invalid_hour(std::string msg) : invalid_argument(msg)
{
}

invalid_min::invalid_min(std::string msg) : invalid_argument(msg)
{
}

invalid_sec::invalid_sec(std::string msg) : invalid_argument(msg)
{
}
