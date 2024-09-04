#include <gtest/gtest.h>
#include <cmath>
#include "../drink.h"

TEST(drinkTest, constructorAndGetterTest)
{
    drink d(TEA, BLEND, LARGE, "None", "Sugar");
    drink d1(COFFEE, HOT, SMALL, "None", "Sugar");
    drink d2(CREAM, ICE, MED, "Milk", "Raspberry");
    EXPECT_STRCASEEQ(d.getBaseStr().c_str(), "Tea");
    EXPECT_STRCASEEQ(d.getTemperature().c_str(), "Blended");
    EXPECT_STRCASEEQ(d.getSize().c_str(), "Large");
    EXPECT_STRCASEEQ(d.getFlavor().c_str(), "Sugar");
    EXPECT_STRCASEEQ(d.getDairy().c_str(), "None");
}

extern "C" int startTest(int x, char **y)
{
    testing::InitGoogleTest(&x, y);
    int code = RUN_ALL_TESTS();
    return code;
}

extern "C" int __wrap_main(int x, char **y)
{
    return startTest(x, y);
}