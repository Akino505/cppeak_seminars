#include "SmartLight.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

void SmartLight::turnOn()
{
    _isOn = true;
    std::cout << "The LAMP: [" << getName() << "] is ON" << "\n";
}

void SmartLight::turnOff()
{
    _isOn = false;
    std::cout << "The LAMP: [" << getName() << "] is OFF" << "\n";
}

void SmartLight::configure(const std::string& params)
{
    int bright = 0;
    if(params.find("brightness=") != 0)
    {
        std::stringstream error;
        error << "Smart Light: [" << getName()
              << "]: Parameter shoud be 'brightness=<0-100>'";
        throw std::invalid_argument(error.str());
    }
    try
    {
        bright = std::stoi(params.substr(11));
    }
    catch(...)
    {
        std::stringstream error;
        error << "Smart Light: [" << getName() << "]: Percent shoud me integer";
        throw std::invalid_argument(error.str());
    }
    if(bright < 0 || bright > 100)
    {
        std::stringstream error;
        error << "Smart Light: [" << getName()
              << "]: Brightness must be from 0 to 100 percents";
        throw std::out_of_range(error.str());
    }
    _brightness = bright;
}

std::string SmartLight::getStatus() const
{
    return "[" + getName() + "]: " + (isOn() ? "ON" : "OFF") +
           ", BRIGHTNESS: " + std::to_string(_brightness) + "%" + "\n";
}