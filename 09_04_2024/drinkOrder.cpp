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

void drinkOrder::addDrink(const drink &d)
{
    drinks[numDrinks] = new drink(d);
    numDrinks++;
    drink **dcpy;
    dcpy = drinks;
    drinks = new drink *[numDrinks + 1];
    for (int i = 0; i < numDrinks; i++)
    {
        drinks[i] = dcpy[i];
    }
    delete[] dcpy;
}

void drinkOrder::addDrinks(drink **d, int numD)
{
    int oldNum = this->numDrinks;
    this->numDrinks += numD;
    drink **dcpy;
    dcpy = drinks;
    this->drinks = new drink *[this->numDrinks + 1];
    for (int i = 0; i < oldNum; i++)
    {
        this->drinks[i] = dcpy[i];
    }
    int j = 0;
    for (int i = oldNum; i < this->numDrinks; i++)
    {
        drinks[i] = new drink(*d[j]);
        j++;
    }
    delete[] dcpy;
}

std::string drinkOrder::toString() const
{
    std::ostringstream out;
    out << "This order has " << numDrinks << " drinks:" << std::endl;
    for (int i = 0; i < numDrinks; i++)
    {
        out << drinks[i]->tostring() << std::endl;
        out << std::setw(25) << std::setfill('-') << "-" << std::endl;
    }
    return out.str();
}
