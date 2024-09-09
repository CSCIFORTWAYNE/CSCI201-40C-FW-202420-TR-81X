#include "order.h"

order::order()
{
    numProducts = 0;
    products = new product *[numProducts + 1];
    products[0] = nullptr;
}

void order::addProduct(product &d)
{

    products[numProducts] = d.clone();
    product **dcpy;
    dcpy = products;
    products = new product *[++numProducts + 1];
    for (int i = 0; i < numProducts; i++)
    {
        products[i] = dcpy[i];
    }
    delete[] dcpy;
}

/* void order::addDrinks(drink **d, int numD)
{
    int oldNum = numProducts;
    numProducts += numD;
    drink **dcpy;
    dcpy = products;
    products = new drink *[numProducts + 1];
    for (int i = 0; i < oldNum; i++)
    {
        products[i] = dcpy[i];
    }
    int j = 0;
    for (int i = oldNum; i < numProducts; i++)
    {
        products[i] = new drink(*d[j++]);
    }
} */

order::order(const order &otherOrder)
{
    this->numProducts = otherOrder.numProducts;
    this->products = new product *[this->numProducts + 1];
    for (int i = 0; i < numProducts; i++)
    {
        this->products[i] = otherOrder.products[i]->clone();
    }
}

order::~order()
{
    for (int i = 0; i < numProducts; i++)
    {
        delete products[i];
    }
    delete[] products;
}

std::string order::tostring() const
{
    std::ostringstream out;
    out << "This order has " << numProducts << " products:" << std::endl;
    for (int i = 0; i < numProducts; i++)
    {
        out << products[i]->tostring() << std::endl;
        out << std::setw(25) << std::setfill('-') << "-" << std::endl;
    }
    return out.str();
}