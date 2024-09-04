#ifndef DRINK_H
#define DRINK_H

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
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

class drink
{
public:
    drink(baseType, tempType, sizeType, std::string dairy, std::string flavor);
    // drink(baseType, tempType, sizeType, std::string dairy, std::string flavor, std::string description, std::string prodNum);
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

private:
    baseType base;
    tempType temperature;
    sizeType size;
    std::string dairy;
    std::string flavor;
    static int numDrinks;
};

#endif