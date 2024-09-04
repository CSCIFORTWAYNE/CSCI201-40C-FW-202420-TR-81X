#include "drinkOrder.h"

drinkOrder::drinkOrder()
{
    numDrinks = 0;
    drinks = new drink *[numDrinks + 1];
    drinks[0] = nullptr;
}

drinkOrder::drinkOrder(const drinkOrder &otherDrinkOrder)
{
    this->numDrinks = otherDrinkOrder.numDrinks;
    this->drinks = new drink *[this->numDrinks + 1];
    for (int i = 0; i < this->numDrinks; i++)
    {
        drinks[i] = new drink(*otherDrinkOrder.drinks[i]);
    }
}

drinkOrder::~drinkOrder()
{
    for (int i = 0; i < numDrinks; i++)
    {
        delete drinks[i];
    }

    delete[] drinks;
}