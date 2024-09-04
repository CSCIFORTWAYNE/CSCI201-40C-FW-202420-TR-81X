#ifndef DRINKORDER_H
#define DRINKORDER_H
#include "drink.h"
#include <string>
#include <sstream>
class drinkOrder
{
public:
    drinkOrder();
    drinkOrder(const drinkOrder &);
    ~drinkOrder();

private:
    drink **drinks;
    int numDrinks;
};

#endif