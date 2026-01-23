#include "mult.h"
#include <catch2/catch_test_macros.hpp>


TEST_CASE("Testing multiplication function"){
    SECTION("Positive numbers"){
        REQUIRE(multiply(2, 4) == 8);
        REQUIRE(multiply(1000000, 1000000) == 1000000000000);
    }

    SECTION("Negative numbers"){
        REQUIRE(multiply(-2, -4) == 8);
        REQUIRE(multiply(-1000000, -1000000) == 1000000000000);
    }

    SECTION("Positive and negative numbers"){
        REQUIRE(multiply(-2, 4) == -8);
        REQUIRE(multiply(7, -4) == -28);
        REQUIRE(multiply(1000000, -1000000) == -1000000000000);
    }

    SECTION("Multiplication with zero"){
        REQUIRE(multiply(2, 0) == 0);
        REQUIRE(multiply(-2, 0) == 0);
        REQUIRE(multiply(0, 100000000000) == 0);
    }
}
