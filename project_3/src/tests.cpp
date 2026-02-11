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
    SECTION("One element")
    {
        REQUIRE(median(3.14) == (3.14, NULL));
        REQUIRE(median(1) == (1, NULL));
        REQUIRE(median(-2) == (-2, NULL));
    }

    SECTION("Even amount")
    {
        REQUIRE(median(3.14, -2.13, 4.0, 2) == (3.14, 2.0));
        REQUIRE(median(1, 2, 3, 4) == (2.0, 3.0));
        REQUIRE(median(-12.0, 3.0, 0, 1) == (0.0, 1.0));
    }

    SECTION("Odd amount")
    {
        REQUIRE(median(3.14, -2.13, 4.0) == (3.14, NULL));
        REQUIRE(median(1, 2, 3) == (2.0, NULL));
        REQUIRE(median(-12.0, 3.0, 0) == (0.0, NULL));
    }

    SECTION("Duplicates inside")
    {
        REQUIRE(median(0, 0, 0, 0) == (0.0, 0.0));
        REQUIRE(median(2, 2, 1) == (2.0, NULL));
        REQUIRE(median(-12.0, 3.0, 3.0, 1) == (1.0, 3.0));
    }
}

TEST_CASE("Testing mean deviation function")
{
    
}

TEST_CASE("Testing safety of rows and calumns values")
{   
    SECTION("Is integer")
    {
        REQUIRE(safeInput(3.14) == false);
        REQUIRE(safeInput(3) == true);
    }

    SECTION("Is positive")
    {
        REQUIRE(safeInput(-3) == false);
        REQUIRE(safeInput(0) == false);
        REQUIRE(safeInput(-3.14) == false);
        REQUIRE(safeInput(3) == true);
    }
}

TEST_CASE("Testing appropriate amount of digits in matrix")
{
    
}