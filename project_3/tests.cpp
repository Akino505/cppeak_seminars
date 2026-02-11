#include <catch2/catch_test_macros.hpp>
#include "mode.h"

TEST_CASE("Testing mode function"){
    SECTION("Simple"){
        REQUIRE(mode(1, 1, 1, 1, 0, 0, 1, 1, 1) == 1);
        REQUIRE(mode(1, 1, 2, 2) == 1);
        REQUIRE(muode(2, 0, 1, 3, 4, 5) == 2);
        REQUIRE(muode(2, 0, 1, 3, 4, 3) == 3);
    }
}