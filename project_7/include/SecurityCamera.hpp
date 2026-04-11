#ifndef SECURITY_CAMERA_HPP
#define SECURITY_CAMERA_HPP

#include "SmartDevice.hpp"

enum class CameraMode
{
    MOTION,
    CONTINUOUS
};

class SecurityCamera: public SmartDevice
{
public:
    void turnOn() override;
    void turnOff() override;
    void configure(const std::string& params) override;
    std::string getStatus() const override;

private:
    CameraMode _mode = CameraMode::MOTION;
};
#endif