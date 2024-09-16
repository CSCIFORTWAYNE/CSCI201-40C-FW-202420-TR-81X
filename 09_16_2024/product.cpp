#include "product.h"

product::product(std::string prodNum, double price, std::string description, int hr, int min, int sec) : myClock(hr, min, sec)
{
    setPrice(price);
    setDescription(description);
    if (!prodNum.empty())
    {
        this->prodNum = prodNum;
    }
    else
    {
        std::cout << "Product number cannot be empty" << std::endl;
        this->prodNum = "1";
    }
    purchased = false;
}

std::string product::getProductNum() const
{
    return prodNum;
}

std::string product::getDescription() const
{
    return description;
}

double product::getPrice() const
{
    return price;
}

void product::purchase()
{
    purchased = true;
}

bool product::isPurchased() const
{
    return purchased;
}

void product::setPrice(double price)
{
    if (price > 0)
    {
        this->price = price;
    }
    else
    {
        std::cout << "Price must be greater than 0." << std::endl;
        this->price = 1;
    }
}

void product::setDescription(std::string description)
{
    this->description = description;
}

std::string product::tostring() const
{
    std::ostringstream out;
    out << std::setprecision(2) << std::fixed << std::showpoint;
    /*
        std::string purch;
        if(purchased)
        {
            purch = "Not Available";
        }
        else
        {
            purch = "Available";
        }
    */
    std::string purch = purchased ? "Not Available" : "Available";
    out << prodNum << " - " << description << " - $" << price << " - " << purch;
    return out.str();
}

int drink::numDrinks = 0;

std::string drink::getBaseStr() const
{
    return baseToString[base];
}

std::string drink::getTemperature() const
{
    // return tempStr[temperature];
}

drink::drink(baseType b, tempType t, sizeType s, std::string d, std::string f) : product("drink" + std::to_string(++drink::numDrinks))
{
    setBase(b);
    setTemperature(t);
    setSize(s);
    setDairy(d);
    setFlavor(f);
    // product::setPrice(getPrice());
    description = getBaseStr() + " " + getTemperature() + " " + getSize();
    price = getPrice();
}

std::string drink::getSize() const
{
    // return sizeStr[size];
}
std::string drink::getDairy() const
{
    return dairy;
}
std::string drink::getFlavor() const
{
    return flavor;
}
/* drink::drink()
{
    setBase(COFFEE);
    setSize(LARGE);
    setTemperature(HOT);
    dairy = "";
    flavor = "";
} */
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
    if (dairyCpy == "whole milk")
    {
        price += .5;
    }
    else if (dairyCpy == "skim milk")
    {
        price += .75;
    }
    else if (dairyCpy == "cream")
    {
        price += 1.5;
    }
    else if (dairyCpy == "oat milk" || dairyCpy == "almond milk")
    {
        price += 2.0;
    }
    else
    {
        price += .5;
    }

    return price;
}

void drink::setBase(baseType b)
{
    bool set = false;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        if (baseToString.count(b))
        {
            base = b;
            set = true;
            break;
        }
    }
    if (!set)
    {
        base = COFFEE;
    }
}

void drink::setTemperature(tempType t)
{
    bool set = false;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        // if (t == temps[i])
        {
            temperature = t;
            set = true;
            break;
        }
    }
    if (!set)
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
    bool set = false;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        // if (s == sizes[i])
        {
            size = s;
            set = true;
            break;
        }
    }
    if (!set)
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
    out << product::tostring() << std::endl;
    return out.str();
}

drink::drink(baseType b, tempType t, sizeType s, std::string d, std::string f, std::string description, std::string prodNum) : product(prodNum, 0.01, description)
{
    drink::numDrinks++;
    setBase(b);
    setTemperature(t);
    setSize(s);
    setDairy(d);
    setFlavor(f);
    product::setPrice(getPrice());
}

double iceCream::scoopPricing(int scoops)
{
    switch (scoops)
    {
    case 1:
        return 3.0;
    case 2:
        return 4.0;
    case 3:
        return 5.0;
    default:
        return scoops * 1.65;
    }
    return 0.0;
}
int iceCream::prodNum = 1;
iceCream::iceCream(flavorType flavor, int scoopAmount) : product("Ice Cream", scoopPricing(scoopAmount), "I" + std::to_string(prodNum++))
{
    setFlavor(flavor);
    setScoopAmount(scoopAmount);
    purchase();
}
void iceCream::setFlavor(flavorType f)
{
    flavor = f;
}
void iceCream::setScoopAmount(int x)
{
    if (x < 1)
    {
        x = 1;
    }
    scoopAmount = x;
}
std::string iceCream::tostring() const
{
    std::ostringstream out;
    out << scoopAmount << " scoops of "
        << "Flavor string"
        << " - " << product::tostring();
    return out.str();
}

iceCream *iceCream::clone()
{
    return new iceCream(*this);
}

iceCream::~iceCream()
{
    std::cout << "ice cream destructor" << std::endl;
}
drink *drink::clone()
{
    return new drink(*this);
}
drink::~drink()
{
    std::cout << "drink destructor" << std::endl;
}
product::~product()
{
    std::cout << "product destructor" << std::endl;
}

std::map<baseType, std::string> drink::baseToString = {{COFFEE, "Coffee"},
                                                       {CREAM, "Cream"},
                                                       {TEA, "Tea"}};
std::map<std::string, baseType> drink::stringToBase = {{"tea", TEA},
                                                       {"cream", CREAM},
                                                       {"coffee", COFFEE}};
std::set<std::string> drink::dairyOptions = {"Whole Milk",
                                             "Skim Milk",
                                             "Almond Milk",
                                             "Oat Milk",
                                             "Cream",
                                             "Half & Half",
                                             "None"};