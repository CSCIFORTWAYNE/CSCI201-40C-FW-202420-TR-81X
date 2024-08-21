#include "drink.h"

drink::drink(baseType b, tempType t, sizeType s, flavType f[], int nf, std::string d)
{
    base = b;
    temperature = t;
    size = s;
    dairy = d;
    numFlavs = nf;
    for (int i = 0; i < nf; i++)
    {
        flavors[i] = f[i];
    }
}

std::string drink::getBaseStr() const
{
    return baseStr[base];
}

std::string drink::getTemperature() const
{
    return tempStr[temperature];
}

std::string drink::getSize() const
{
    return sizeStr[size];
}

std::string drink::getDairy() const
{
    return dairy;
}

std::string drink::getFlavor() const
{
    std::ostringstream strOut;
    if (numFlavs > 0)
    {
        strOut << flavStr[flavors[0]];
    }
    for (int i = 1; i < numFlavs; i++)
    {
        strOut << ", " << flavStr[flavors[i]];
    }
    return strOut.str();
}

double drink::getPrice() const
{
    return 0.0;
}
