#include <string>

class SmartDevice
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual std::string getStatus() const = 0;
    virtual void configure(const std::string& params) = 0;
    virtual ~SmartDevice() = default;
    std::string getName() const { return _name; }
    int getId() const { return _id; }
    bool isOn() const { return _isOn; }

protected:
    SmartDevice(int id, const std::string& name): _id(id), _name(name), _isOn(false) {}
    int _id;
    std::string _name;
    bool _isOn;
};