#ifndef SMART_LIGHT_HPP
#define SMART_LIGHT_HPP

#include "SmartDevice.hpp"

class SmartLight: public SmartDevice
{
public:
    SmartLight(int id, const std::string& name, int brightness = 50)
        : SmartDevice(id, name), _brightness(brightness)
    {
    }
    void turnOn() override;
    void turnOff() override;
    void configure(const std::string& params) override;
    std::string getStatus() const override;
    int getBrightness() const { return _brightness; }

private:
    int _brightness;
};

#endif