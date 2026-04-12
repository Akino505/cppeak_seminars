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
    SecurityCamera(int id, const std::string& name,
                   CameraMode mode = CameraMode::MOTION)
        : SmartDevice(id, name), _mode(mode)
    {
    }
    void turnOn() override;
    void turnOff() override;
    void configure(const std::string& params) override;
    std::string getStatus() const override;
    CameraMode getMode() const { return _mode; }

private:
    CameraMode _mode = CameraMode::MOTION;
};
#endif