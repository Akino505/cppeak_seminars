#include "Thermostat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

void Thermostat::turnOn()
{
    _isOn = true;
    std::cout << "The THERMOSTAT: [" << getName() << "] is ON" << "\n";
}

void Thermostat::turnOff()
{
    _isOn = false;
    std::cout << "The THERMOSTAT: [" << getName() << "] is OFF" << "\n";
}

void Thermostat::configure(const std::string& params)
{
    if(params.find("temperature=") != 0)
    {
        throw std::invalid_argument(
            "Parameter shoud be 'temperature=<number>'");
    }
    std::string stringTemp = params.substr(12);
    double temp = 0;
    try
    {
        temp = std::stod(stringTemp);
    }
    catch(...)
    {
        throw std::invalid_argument("The temperature should be number");
    }
    if(temp < -30.0 || temp > 50.0)
    {
        throw std::out_of_range(
            "The temperature shoud be between -30.0 and +50.0");
    }
    _temperature = temp;
}

std::string Thermostat::getStatus() const
{
    return "[" + getName() + "] " + (isOn() ? "ON" : "OFF") +
           " TEMPERATURE: " + std::to_string(_temperature);
}