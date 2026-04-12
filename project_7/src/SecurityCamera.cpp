#include "SecurityCamera.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

void SecurityCamera::turnOn()
{
    _isOn = true;
    std::cout << "The CAMERA: [" << getName() << "] is ON" << "\n";
}

void SecurityCamera::turnOff()
{
    _isOn = false;
    std::cout << "The CAMERA: [" << getName() << "] is OFF" << "\n";
}

void SecurityCamera::configure(const std::string& params)
{
    if(params.find("mode=") != 0)
    {
        std::stringstream error;
        error << "Security Camera: [" << getName()
              << "]: Parameter shoud be 'mode=[motion|continuous]'";
        throw std::invalid_argument(error.str());
    }
    std::string stringMode = params.substr(5);
    if(!(stringMode == "motion" || stringMode == "continuous"))
    {
        std::stringstream error;
        error << "Security Camera: [" << getName()
              << "]: Mode should be 'motion' or 'continuous'";
        throw std::out_of_range(error.str());
    }
    _mode =
        (stringMode == "motion" ? CameraMode::MOTION : CameraMode::CONTINUOUS);
}

std::string SecurityCamera::getStatus() const
{
    return "[" + getName() + "]: " + (isOn() ? "ON" : "OFF") + ", MODE: " +
           (_mode == CameraMode::MOTION ? "MOTION" : "CONTINUOUS") + "\n";
}