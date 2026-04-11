#include "SmartDevice.hpp"
#include <sys/types.h>

enum class CameraMode
{
    Motion,
    Continuous
};

class SecurityCamera: public SmartDevice
{
public:
    void turnOn() override;
    void turnOff() override;
    void configure(const std::string& params) override;
    std::string getStatus() const override;

private:
    CameraMode _mode = CameraMode::Motion;
};