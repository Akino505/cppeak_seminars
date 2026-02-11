#include <catch2/catch_test_macros.hpp>
#include "mode.hpp"
#include "median.hpp"
#include "meanDeviation.hpp"
#include "safeInput.hpp"
#include "appropriateSize.hpp"

TEST_CASE("Testing mode function"){
    SECTION("Simple"){
        REQUIRE(mode(1, 1, 1, 1, 0, 0, 1, 1, 1) == 1);
        REQUIRE(mode(1, 1, 2, 2) == 1);
        REQUIRE(muode(2, 0, 1, 3, 4, 5) == 2);
        REQUIRE(muode(2, 0, 1, 3, 4, 3) == 3);
    }
}

TEST_CASE("Testing median function")
{

}

TEST_CASE("Testing mean deviation function")
{
    
}

TEST_CASE("Testing safety of rows and calumns values")
{
    
}

TEST_CASE("Testing appropriate amount of digits in matrix")
{
    
}