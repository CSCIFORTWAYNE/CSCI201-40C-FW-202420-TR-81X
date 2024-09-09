#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "clock.h"

class product
{
public:
    product(std::string prodNum, double price = 0.01, std::string description = "", int hr = 0, int min = 0, int sec = 0);
    std::string getProductNum() const;
    std::string getDescription() const;
    double getPrice() const;
    void purchase();
    bool isPurchased() const;
    void setPrice(double);
    void setDescription(std::string);
    virtual std::string tostring() const;
    virtual product *clone() = 0;
    virtual ~product();

protected:
    double price;
    std::string description;
    std::string prodNum;
    bool purchased;
    clockType myClock;
};

enum baseType
{
    COFFEE,
    TEA,
    CREAM
};
enum sizeType
{
    SMALL,
    MED,
    LARGE
};
enum tempType
{
    HOT,
    ICE,
    BLEND
};
const int ENUM_NUM = 3;
const baseType bases[] = {COFFEE,
                          TEA,
                          CREAM};
const std::string baseStr[] = {"Coffee", "Tea", "Cream"};
const std::string strBase[] = {"COFFEE", "TEA", "CREAM"};
const sizeType sizes[] = {SMALL,
                          MED,
                          LARGE};
const std::string sizeStr[] = {"Small", "Medium", "Large"};
const tempType temps[] = {HOT,
                          ICE,
                          BLEND};
const std::string tempStr[] = {"Hot", "Iced", "Blended"};

class drink : public product
{
public:
    drink(baseType, tempType, sizeType, std::string dairy, std::string flavor);
    drink(baseType, tempType, sizeType, std::string dairy, std::string flavor, std::string description, std::string prodNum);
    // drink();
    std::string getBaseStr() const;
    std::string getTemperature() const;
    std::string getSize() const;
    std::string getDairy() const;
    std::string getFlavor() const;
    double getPrice() const;
    void setBase(baseType);
    void setTemperature(tempType);
    void setSize(sizeType);
    void setDairy(std::string);
    void setFlavor(std::string);
    std::string tostring() const;
    drink *clone();
    ~drink();

private:
    baseType base;
    tempType temperature;
    sizeType size;
    std::string dairy;
    std::string flavor;
    static int numDrinks;
};
enum flavorType
{
    VANILLAICECREAM,
    CHOCOLATEICECREAM,
    STRAWBERRY,
    MINT_CHOCOLATE_CHIP,
    COOKIE_DOUGH,
    COOKIES_AND_CREAM,
    BUTTER_PECAN,
    ROCKY_ROAD,
    CHOCOLATE_CHIP,
    MOOSE_TRACKS,

    CHOCOLATE_FUDGE_BROWNIE,
    PISTACHIO,
    RUM_RAISIN,
    NEAPOLITAN,
    FRENCH_VANILLA,
    PEANUT_BUTTER_CUP,
    BLACK_RASPBERRY,
    BIRTHDAY_CAKE,
    CARAMEL_SWIRL,
    MAPLE_WALNUT,
    BANANA_SPLIT,
    TUTTI_FRUTTI,
    ORANGE_SHERBET,
    COCONUTICECREAM

};

class iceCream : public product
{
public:
    iceCream(flavorType = VANILLAICECREAM, int = 1);
    // lecture activity fill-in getters and setters
    flavorType getFlavor() const;
    int getScoopAmount() const;
    void setFlavor(flavorType);
    void setScoopAmount(int);
    std::string tostring() const;
    static double scoopPricing(int);
    iceCream *clone();
    ~iceCream();

private:
    flavorType flavor;
    int scoopAmount;
    static int prodNum;
};
#endif