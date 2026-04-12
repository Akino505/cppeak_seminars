#ifndef THERMOSTAT_HPP
#define THERMOSTAT_HPP

#include "SmartDevice.hpp"

class Thermostat: public SmartDevice
{
public:
    Thermostat(int id, const std::string& name, double temperature = 20.0)
        : SmartDevice(id, name), _temperature(temperature)
    {
    }
    void turnOn() override;
    void turnOff() override;
    void configure(const std::string& params) override;
    std::string getStatus() const override;
    double getTemperature() const { return _temperature; }

private:
    double _temperature;
};

#endif