#ifndef THERMOSTAT_HPP
#define THERMOSTAT_HPP

#include "SmartDevice.hpp"

class Thermostat: public SmartDevice
{
public:
    void turnOn() override;
    void turnOff() override;
    void configure(const std::string& params) override;
    std::string getStatus() const override;

private:
    double _temperature;
};

#endif