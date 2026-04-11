#ifndef SMART_LIGHT_HPP
#define SMART_LIGHT_HPP

#include "SmartDevice.hpp"

class SmartLight: public SmartDevice
{
public:
    void turnOn() override;
    void turnOff() override;
    void configure(const std::string& params) override;
    std::string getStatus() const override;

private:
    int _brightness;
};

#endif