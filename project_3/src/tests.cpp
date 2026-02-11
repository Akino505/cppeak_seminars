#include <catch2/catch_test_macros.hpp>
#include "mode.hpp"
#include "median.hpp"
#include "meanDeviation.hpp"
#include "safeInput.hpp"
#include "appropriateSize.hpp"

TEST_CASE("Testing mode function"){
    SECTION("One element")
    {
        REQUIRE(mode({3.14}) == 3.14);
        REQUIRE(mode({1}) == 1.0);
        REQUIRE(mode({-2}) == -2.0);
    }

    SECTION("All elements are equal") {
        REQUIRE(mode({5.0, 5, 5.0, 5}) == 5.0);
        REQUIRE(mode({-1.0, -1, -1.0}) == -1.0);
        REQUIRE(mode({3.14, 3.14, 3.14}) == 3.14);
    }

    SECTION("All elements are unique") {
        REQUIRE(mode({1, 2.0, 3.0, -4.0, 5.0}) == 1.0);
        REQUIRE(mode({10.0, 20, 30.0}) == 10.0);
        REQUIRE(mode({-5.0, 0.0, 5.0}) == -5.0);
    }

    SECTION("Single mode") {
        REQUIRE(mode({1.0, 2.0, 2.0, 3.0, 4.0}) == 2.0);
        REQUIRE(mode({10.0, -20.0, 30.0, 30.0, 30.0, 40}) == 30.0);
        REQUIRE(mode({1.5, 1.5, 1.5, 2.5}) == 1.5);
        REQUIRE(mode({-5.0, -5.0, -5.0, -10.0}) == -5.0);
    }

    SECTION("More than one mode") {
        REQUIRE(mode({1.0, 1.0, 2.0, 2, 3.0}) == 1.0);
        REQUIRE(mode({5.0, 5, 7.0, 7.0, 9.0, 9.0}) == 5.0);
        REQUIRE(mode({1.0, 1, 1.0, 2.0, 2.0, 2.0}) == 1.0);
        REQUIRE(mode({-1.0, -1.0, -2.0, -2.0}) == -1.0);
    }
}

TEST_CASE("Testing median function")
{
    SECTION("One element")
    {
        REQUIRE(median({3.14}) == (3.14, NULL));
        REQUIRE(median({1}) == (1, NULL));
        REQUIRE(median({-2}) == (-2, NULL));
    }

    SECTION("Even amount")
    {
        REQUIRE(median({3.14, -2.13, 4.0, 2}) == (3.14, 2.0));
        REQUIRE(median({1, 2, 3, 4}) == (2.0, 3.0));
        REQUIRE(median({-12.0, 3.0, 0, 1}) == (0.0, 1.0));
    }

    SECTION("Odd amount")
    {
        REQUIRE(median({3.14, -2.13, 4.0}) == (3.14, NULL));
        REQUIRE(median({1, 2, 3}) == (2.0, NULL));
        REQUIRE(median({-12.0, 3.0, 0}) == (0.0, NULL));
    }

    SECTION("Duplicates inside")
    {
        REQUIRE(median({0, 0, 0, 0}) == (0.0, 0.0));
        REQUIRE(median({2, 2, 1}) == (2.0, NULL));
        REQUIRE(median({-12.0, 3.0, 3.0, 1}) == (1.0, 3.0));
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
    SECTION("More than expected")
    {
        REQUIRE(appropriateSize({1, 2, 3, 4}, 3) == false);
        REQUIRE(appropriateSize({1.2, -2, -3.123, 4}, 0) == false);
    }

    SECTION("Less than expected")
    {
        REQUIRE(appropriateSize({1, 2, 3, 4}, 6) == false);
        REQUIRE(appropriateSize({-1.232, 2, -3, 4.0}, 9) == false);
    }

    SECTION("Equal expected")
    {
        REQUIRE(appropriateSize({1, 2, 3, 4}, 4) == true);
        REQUIRE(appropriateSize({1.0, -2, -3.232, 4}, 4) == true);
    }
}