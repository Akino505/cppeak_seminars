#include <catch2/catch_test_macros.hpp>
#include "check_len.h++"
#include "check_big.h++"
#include "check_small.h++"
#include "check_digit.h++"
#include "check_specials.h++"
#include "check_bad_specials.h++"
#include "specials.h++"

TEST_CASE("Testing multiplication function")
{
    SECTION("Lenght")
    {
        REQUIRE(check_len("Hi!1") == false);
        REQUIRE(check_len("Lennn=7") == false);
        REQUIRE(check_len("Length=8") == true);
        REQUIRE(check_len("Hello!It`s_me1") == true);
    }

    SECTION("Digits")
    {
        REQUIRE(check_digit("Hello!It`s_me") == false);
        REQUIRE(check_digit("Hello!It`s_me1") == true);
    }

    SECTION("Small letters")
    {
        REQUIRE(check_small("HELLO!IT`S_ME1") == false);
        REQUIRE(check_small("Hello!It`s_me1") == true);
    }

    SECTION("Capital letters")
    {
        REQUIRE(check_big("hello!it`s_me1") == false);
        REQUIRE(check_big("Hello!It`s_me1") == true);
    }

    SECTION("Specials")
    {
        REQUIRE(check_specials("HelloITSME1") == false);
        REQUIRE(check_specials("Hello!It`s_me1") == true);
    }

    SECTION("Bad specials")
    {
        REQUIRE(check_bad_specials("Hello!ЭТ0_Я") == false);
        REQUIRE(check_bad_specials("Hello!      It`s_me1") == false);
        REQUIRE(check_bad_specials("Hello!It`s_me1") == true);
    }
}