#ifndef HOME_HUB_HPP
#define HOME_HUB_HPP

#include "SmartDevice.hpp"
#include <vector>
#include <memory>
#include <string>
#include <unordered_set>

class HomeHub
{
public:
    HomeHub() = default;
    
    void addDevice(std::unique_ptr<SmartDevice> device);
    void activateAll();
    void deactivateAll();
    void generateReport() const;
    void sendCommand(int id, const std::string& cmd);

private:
    std::vector<std::unique_ptr<SmartDevice>> _devices;
    std::unordered_set<int> _usedIds;
    
    SmartDevice* _findDeviceById(int id);
};

#endif