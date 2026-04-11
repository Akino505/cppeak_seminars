#include "SmartLight.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

void SmartLight::turnOn()
{
    _isOn = true;
    std::cout << "The device: [" << getName() << "] is ON." << "\n";
}

void SmartLight::turnOff()
{
    _isOn = false;
    std::cout << "The device: [" << getName() << "] is OFF." << "\n";
}

std::string SmartLight::getStatus() const
{
    return "[" + getName() + "]: is " + (isOn() ? "ON" : "OFF") +
           ", BRIGHTNESS: " + std::to_string(_brightness) + "%.";
}

void SmartLight::configure(const std::string& params)
{
    if(params.find("brightness=") == 0)
        throw std::invalid_argument("Parameter shoud be 'brightness=<0-100>'");
    int brght = std::stoi(params.substr(11));
    if(brght < 0 || brght > 100)
        throw std::invalid_argument(
            "Brightness must be from 0 to 100 percents");
    _brightness = brght;
}