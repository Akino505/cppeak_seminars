#include "Thermostat.hpp"
#include <catch2/catch_test_macros.hpp>
#include <stdexcept>

TEST_CASE("Thermostat: default initialisasion.", "[device][thermostat]")
{
    Thermostat temp(1, "Temp");
    CHECK(!temp.isOn());
    CHECK(temp.getId() == 1);
    CHECK(temp.getName() == "Temp");
    CHECK(temp.getTemperature() == 20.0);
}

TEST_CASE("Thermostat: isOn.", "[isOn][thermostat]")
{
    Thermostat temp(1, "Temp");
    temp.turnOn();
    CHECK(temp.isOn());
    temp.turnOff();
    CHECK(!temp.isOn());
}

TEST_CASE("Thermostat: configure with validation.", "[configure][thermostat]")
{
    Thermostat temp(1, "Temp");
    CHECK_NOTHROW(temp.configure("temperature=90"));
    temp.configure("temperature=9.12");
    CHECK(temp.getTemperature() == 9.12);
    CHECK(!temp.isOn());
    temp.turnOn();
    temp.configure("temperature=0");
    CHECK(temp.getTemperature() == -30.0);
    temp.configure("temperature=100");
    CHECK(temp.getTemperature() == 50.0);
    CHECK_THROWS_AS(temp.configure("wrong_key=90"), std::invalid_argument);
    CHECK_THROWS_AS(temp.configure("temperature=asd1"), std::invalid_argument);
    CHECK_THROWS_AS(temp.configure("temperature=2000"), std::out_of_range);
    CHECK_THROWS_AS(temp.configure("temperature=-1232"), std::out_of_range);
}