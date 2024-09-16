#ifndef DRINKORDER_H
#define DRINKORDER_H
#include "product.h"
#include <string>
#include <sstream>

class order
{

public:
    order();
    order(const order &otherOrder);
    void addProduct(product &);
    const order &operator=(const order &rightOrder);
    product &operator[](int index);
    const product &operator[](int index) const;
    // void addDrink()
    //  void addDrinks(drink **, int);
    ~order();
    std::string tostring() const;

private:
    void copyOrder(const order &otherOrder);
    product **products;
    int numProducts;
};

#endif