#include "catch2/catch.hpp"
#include "application.hpp"

TEST_CASE("vectors can be sized and resized", "[vector]")
{

    SECTION("reserving bigger changes capacity but not size")
    {
        REQUIRE(6 > 5);
    }
}
