#include <iostream>
#include <limits>
#include "product.h"
#include "order.h"

void resetStream();
void displayProduct(product &p);
drink *createDrink();

int main()
{
    order myOrder;
    char cont = 'y';
    while (cont == 'y')
    {
        std::string productType;
        std::cout << "Do you want to create a drink or ice cream?";
        std::cin >> std::ws;
        getline(std::cin, productType);
        std::transform(productType.begin(), productType.end(), productType.begin(), ::tolower);
        while (productType != "drink" && productType != "ice cream")
        {
            std::cout << "Please enter drink or ice cream." << std::endl;
            std::cin >> std::ws;
            getline(std::cin, productType);
            std::transform(productType.begin(), productType.end(), productType.begin(), ::tolower);
        }

        if (productType == "drink")
        {
            drink *d = createDrink();
            std::cout << d->tostring() << std::endl;
            myOrder.addProduct(*d);
            delete d;
        }
        else
        {
            iceCream *i = new iceCream();
            myOrder.addProduct(*i);
            delete i;
        }
        std::cout << "Do you want to order another product? ";
        std::cin >> cont;
        cont = tolower(cont);
    }
    iceCream i2;
    std::cout << i2.tostring() << std::endl;
    std::cout << myOrder.tostring() << std::endl;

    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayProduct(product &p)
{
    std::cout << p.tostring() << std::endl;
}

drink *createDrink()
{
    int drinkSize;
    int drinkBase;
    int drinkTemp;
    std::string dairy;
    std::string flavor;
    std::cout << "Please choose the drink size:" << std::endl;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        std::cout << i + 1 << ": " << sizeStr[i] << std::endl;
    }
    std::cin >> drinkSize;
    while (!std::cin || drinkSize < 1 || drinkSize > 3)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "You must choose a number from the list." << std::endl;
        std::cout << "Please choose the drink size:" << std::endl;
        for (int i = 0; i < ENUM_NUM; i++)
        {
            std::cout << i + 1 << ": " << sizeStr[i] << std::endl;
        }
        std::cin >> drinkSize;
    }

    std::cout << "Please choose the drink base:" << std::endl;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        std::cout << i + 1 << ": " << baseStr[i] << std::endl;
    }
    std::cin >> drinkBase;
    while (!std::cin || drinkBase < 1 || drinkBase > 3)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "You must choose a number from the list." << std::endl;
        std::cout << "Please choose the drink base:" << std::endl;
        for (int i = 0; i < ENUM_NUM; i++)
        {
            std::cout << i + 1 << ": " << baseStr[i] << std::endl;
        }
        std::cin >> drinkBase;
    }
    std::cout << "Please choose the drink temperature:" << std::endl;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        std::cout << i + 1 << ": " << tempStr[i] << std::endl;
    }
    std::cin >> drinkTemp;
    while (!std::cin || drinkTemp < 1 || drinkTemp > 3)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "You must choose a number from the list." << std::endl;
        std::cout << "Please choose the drink temperature:" << std::endl;
        for (int i = 0; i < ENUM_NUM; i++)
        {
            std::cout << i + 1 << ": " << tempStr[i] << std::endl;
        }
        std::cin >> drinkTemp;
    }
    std::cout << "Please enter a flavor for your drink: ";
    std::cin >> std::ws;
    std::getline(std::cin, flavor);
    std::cout << "What kind of dairy would you like? ";
    std::cin >> std::ws;
    std::getline(std::cin, dairy);
    return new drink(bases[drinkBase - 1], temps[drinkTemp - 1], sizes[drinkSize - 1], dairy, flavor);
}