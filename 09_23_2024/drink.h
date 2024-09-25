#ifndef DRINK_H
#define DRINK_H
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <iostream>
#include <memory>

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
class drink
{
public:
    drink(baseType, tempType, sizeType, std::string dairy, std::string flavor);
    // drink(baseType, tempType, sizeType, std::string dairy, std::string flavor, std::string description, std::string prodNum);
    //  drink();
    drink(std::string base, std::string temp, std::string size, std::string dairy, std::string flavor);
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
    std::unique_ptr<drink> clone();
    ~drink();
    static std::map<baseType, std::string> baseToStr;
    static std::map<std::string, baseType> strToBase;
    static std::map<tempType, std::string> tempToStr;
    static std::map<std::string, tempType> strToTemp;
    static std::map<sizeType, std::string> sizeToStr;
    static std::map<std::string, sizeType> strToSize;
    static std::map<std::string, double> dairyPrice;

private:
    baseType base;
    tempType temperature;
    sizeType size;
    std::string dairy;
    std::string flavor;
    static int numDrinks;
};
#endif