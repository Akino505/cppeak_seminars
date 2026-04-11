#include "Thermostat.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
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
        std::stringstream error;
        error << "Thermostat: [" << getName()
              << "]: Parameter shoud be 'temperature=<number>'";
        throw std::invalid_argument(error.str());
    }
    std::string stringTemp = params.substr(12);
    double temp = 0;
    try
    {
        temp = std::stod(stringTemp);
    }
    catch(...)
    {
        std::stringstream error;
        error << "Thermostat: [" << getName()
              << "]: The temperature should be number";
        throw std::invalid_argument(error.str());
    }
    if(temp < -30.0 || temp > 50.0)
    {
        std::stringstream error;
        error << "Thermostat: [" << getName()
              << "]: The temperature shoud be between -30.0 and +50.0";
        throw std::out_of_range(error.str());
    }
    _temperature = temp;
}

std::string Thermostat::getStatus() const
{
    std::stringstream temp;
    temp << std::fixed << std::setprecision(1) << _temperature;
    return "[" + getName() + "]: " + (isOn() ? "ON" : "OFF") +
           ", TEMPERATURE: " + temp.str() + "\n";
}