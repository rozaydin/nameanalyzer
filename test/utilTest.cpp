#include "catch.hpp"
#include "util.hpp"
#include <vector>

TEST_CASE("util namespace tests")
{
    SECTION("Generated random number must be within the defined range ")
    {
        const int min = 0;
        const int max = 1000;
        std::vector<int> range(100);
        for (auto &i : range)
        {
            int randomNumber = util::generateRandomNumber(min, max);
            // INFO("Generated Number: " << randomNumber);
            REQUIRE((randomNumber >= min && randomNumber <= max));
        }
    }
}
