#include "drink.h"

int drink::numDrinks = 0;

std::map<baseType, std::string> drink::baseToStr = {{COFFEE, "Coffee"}, {TEA, "Tea"}, {CREAM, "Cream"}};
std::map<std::string, baseType> drink::strToBase = {{"COFFEE", COFFEE}, {"TEA", TEA}, {"CREAM", CREAM}};
std::map<tempType, std::string> drink::tempToStr = {{HOT, "Hot"}, {ICE, "Iced"}, {BLEND, "Blended"}};
std::map<std::string, tempType> drink::strToTemp = {{"HOT", HOT}, {"ICED", ICE}, {"BLENDED", BLEND}};
std::map<sizeType, std::string> drink::sizeToStr = {{SMALL, "Small"}, {MED, "Medium"}, {LARGE, "Large"}};
std::map<std::string, sizeType> drink::strToSize = {{"SMALL", SMALL}, {"MEDIUM", MED}, {"LARGE", LARGE}};
std::map<std::string, double> drink::dairyPrice = {{"whole milk", .5},
                                                   {"skim milk", .75},
                                                   {"cream", 1.5},
                                                   {"oat milk", 2.0},
                                                   {"almond milk", 2.0}};
std::string drink::getBaseStr() const
{
    return baseToStr.at(base);
}

std::string drink::getTemperature() const
{
    return tempToStr.at(temperature);
}

drink::drink(baseType b, tempType t, sizeType s, std::string d, std::string f)
{
    setBase(b);
    setTemperature(t);
    setSize(s);
    setDairy(d);
    setFlavor(f);
}

drink::drink(std::string base, std::string temp, std::string size, std::string dairy, std::string flavor)
{
    std::transform(base.begin(), base.end(), base.begin(), ::toupper);
    if (strToBase.count(base))
    {
        setBase(strToBase.at(base));
    }
    else
    {
        setBase(COFFEE);
    }
    std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    if (strToTemp.count(temp))
    {
        setTemperature(strToTemp.at(temp));
    }
    else
    {
        setTemperature(HOT);
    }
    std::transform(size.begin(), size.end(), size.begin(), ::toupper);
    if (strToSize.count(size))
    {
        setSize(strToSize.at(size));
    }
    else
    {
        setSize(SMALL);
    }
    setDairy(dairy);
    setFlavor(flavor);
}

std::string drink::getSize() const
{
    return sizeToStr.at(size);
}
std::string drink::getDairy() const
{
    return dairy;
}
std::string drink::getFlavor() const
{
    return flavor;
}

double drink::getPrice() const
{
    double price = 0;
    switch (size)
    {
    case SMALL:
        price += 2.00;
        break;
    case MED:
        price += 3.00;
        break;
    case LARGE:
        price += 4.00;
        break;
    default:
        price += 4.00;
    }

    switch (base)
    {
    case COFFEE:
        price += 2.75;
        break;
    case TEA:
        price += 1.75;
        break;
    case CREAM:
        price += 0;
        break;
    }
    switch (temperature)
    {
    case HOT:
        price += 0;
        break;
    case ICE:
        price += 0.5;
        break;
    case BLEND:
        price += 0.75;
        break;
    }
    if (!flavor.empty())
    {
        price += .5;
    }
    std::string dairyCpy = dairy;
    std::transform(dairyCpy.begin(), dairyCpy.end(), dairyCpy.begin(), ::tolower);
    if (dairyPrice.count(dairyCpy))
    {
        price += dairyPrice.at(dairyCpy);
    }
    else
    {
        price += .5;
    }

    return price;
}

void drink::setBase(baseType b)
{

    if (baseToStr.count(b))
    {
        base = b;
    }
    else
    {
        base = COFFEE;
    }
}

void drink::setTemperature(tempType t)
{

    if (tempToStr.count(t))
    {
        temperature = t;
    }
    else
    {
        temperature = HOT;
    }
}

void drink::setDairy(std::string d)
{
    dairy = d;
}

void drink::setSize(sizeType s)
{
    if (sizeToStr.count(s))
    {
        size = s;
    }
    else
    {
        size = LARGE;
    }
}

void drink::setFlavor(std::string f)
{
    flavor = f;
}

std::string drink::tostring() const
{
    std::ostringstream out;
    out << std::setprecision(2) << std::fixed << std::showpoint;
    out << "Size: " << getSize() << std::endl;
    out << "Base: " << getBaseStr() << std::endl;
    out << "Temperature: " << getTemperature() << std::endl;
    out << "Flavor: " << flavor << std::endl;
    out << "Dairy: " << dairy << std::endl;
    out << "Price: " << getPrice() << std::endl;
    return out.str();
}

std::unique_ptr<drink> drink::clone()
{
    return std::unique_ptr<drink>(new drink(*this));
}
drink::~drink()
{
    std::cout << "drink destructor" << std::endl;
}
