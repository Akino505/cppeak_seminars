#include "SmartLight.hpp"
#include <catch2/catch_test_macros.hpp>
#include <stdexcept>

TEST_CASE("SmartLight: default initialisasion.", "[device][light]")
{
    SmartLight lamp(1, "Lamp");
    CHECK(!lamp.isOn());
    CHECK(lamp.getId() == 1);
    CHECK(lamp.getName() == "Lamp");
    CHECK(lamp.getBrightness() == 50);
}

TEST_CASE("SmartLight: isOn.", "[isOn][light]")
{
    SmartLight lamp(1, "Lamp");
    lamp.turnOn();
    CHECK(lamp.isOn());
    lamp.turnOff();
    CHECK(!lamp.isOn());
}

TEST_CASE("SmartLight: configure with validation.", "[configure][light]")
{
    SmartLight lamp(1, "Lamp");
    CHECK_NOTHROW(lamp.configure("brightness=90"));
    lamp.configure("brightness=90");
    CHECK(lamp.getBrightness() == 90);
    CHECK(!lamp.isOn());
    lamp.turnOn();
    lamp.configure("brightness=0");
    CHECK(lamp.getBrightness() == 0);
    lamp.configure("brightness=100");
    CHECK(lamp.getBrightness() == 100);
    CHECK_THROWS_AS(lamp.configure("wrong_key=90"), std::invalid_argument);
    CHECK_THROWS_AS(lamp.configure("brightness=asd1"), std::invalid_argument);
    CHECK_THROWS_AS(lamp.configure("brightness=2000"), std::out_of_range);
    CHECK_THROWS_AS(lamp.configure("brightness=-1232"), std::out_of_range);
}