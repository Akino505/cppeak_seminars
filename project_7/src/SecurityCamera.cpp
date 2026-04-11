#include "SecurityCamera.hpp"
#include <iostream>
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
        throw std::invalid_argument(
            "Parameter shoud be 'mode=[motion|continuous]'");
    std::string stringMode = params.substr(5);
    if(!(stringMode == "motion" || stringMode == "continuous"))
        throw std::invalid_argument("Mode should be 'motion' or 'continuous'");
    _mode =
        (stringMode == "motion" ? CameraMode::MOTION : CameraMode::CONTINUOUS);
}

std::string SecurityCamera::getStatus() const
{
    return "[" + getName() + "] " + (isOn() ? "ON" : "OFF") + ", MODE: " +
           (_mode == CameraMode::MOTION ? "Motion" : "Continuous") + "\n";
}