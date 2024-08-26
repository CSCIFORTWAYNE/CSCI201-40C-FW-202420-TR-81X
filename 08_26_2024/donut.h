#ifndef DONUT_H
#define DONUT_H
#include <string>
enum icingType
{
    CHOCOLATEICING,
    CARAMELICING,
    MAPLE,
    VANILLA,
    GLAZE,
    SPECIALICE,
    NOICE
};
enum toppingType
{
    RAINBOWSPR,
    CHOCOLATESPR,
    PEANUTS,
    COCONUT,
    OREO,
    BACON,
    GRAHAM,
    FRUITYPEBBLES,
    REESESPIECES,
    MMS,
    CANDYBAR,
    CHOCOLATECHIPS,
    SEASALT,
    CINSUGAR,
    POWDSUGAR,
    NOTOP
};
enum drizzleType
{
    CARAMELDRIZZLE,
    CHOCOLATEDRIZZLE,
    PEANUTBUTTER,
    RASPBERRY,
    SPECIALDRIZZLE,
    NODRIZZLE
};
const int NUM_ICE = 7;
const int NUM_TOP = 16;
const int NUM_DRIZZLE = 6;
const icingType icings[NUM_ICE] = {CHOCOLATEICING,
                                   CARAMELICING,
                                   MAPLE,
                                   VANILLA,
                                   GLAZE,
                                   SPECIALICE,
                                   NOICE};
const toppingType toppings[NUM_TOP] = {RAINBOWSPR,
                                       CHOCOLATESPR,
                                       PEANUTS,
                                       COCONUT,
                                       OREO,
                                       BACON,
                                       GRAHAM,
                                       FRUITYPEBBLES,
                                       REESESPIECES,
                                       MMS,
                                       CANDYBAR,
                                       CHOCOLATECHIPS,
                                       SEASALT,
                                       CINSUGAR,
                                       POWDSUGAR,
                                       NOTOP};
const drizzleType drizzles[NUM_DRIZZLE] = {CARAMELDRIZZLE,
                                           CHOCOLATEDRIZZLE,
                                           PEANUTBUTTER,
                                           RASPBERRY,
                                           SPECIALDRIZZLE,
                                           NODRIZZLE};
const std::string toppingStr[] = {"Rainbow Sprinkles",
                                  "CHOCOLATESPR",
                                  "PEANUTS",
                                  "COCONUT",
                                  "OREO",
                                  "BACON",
                                  "GRAHAM",
                                  "FRUITYPEBBLES",
                                  "REESESPIECES",
                                  "MMS",
                                  "CANDYBAR",
                                  "CHOCOLATECHIPS",
                                  "SEASALT",
                                  "CINSUGAR",
                                  "POWDSUGAR",
                                  "NOTOP"};
class donut
{
private:
    toppingType topping;
    icingType icing;
    drizzleType drizzle;
};

#endif