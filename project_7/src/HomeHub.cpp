#include "HomeHub.hpp"
#include <iostream>
#include <algorithm>

void HomeHub::addDevice(std::unique_ptr<SmartDevice> device)
{
    if (!device)
    {
        std::cout << "ERROR: attempt to add nullptr device\n";
        return;
    }
    
    int id = device -> getId();
    
    if (_usedIds.find(id) != _usedIds.end())
    {
        std::cout << "ERROR: device with ID:" << id << " already exists\n";
        return;
    }
    
    _usedIds.insert(id);
    
    _devices.push_back(std::move(device));
}


void HomeHub::activateAll()
{
    if (_devices.empty())
    {
        std::cout << "No devices to activate\n";
        return;
    }
    
    for (auto& device : _devices)
    {
        device -> turnOn();
    }
}

void HomeHub::deactivateAll()
{
    if (_devices.empty())
    {
        std::cout << "No devices to deactivate\n";
        return;
    }

    for (auto& device : _devices)
    {
        device -> turnOff();
    }
}

void HomeHub::generateReport() const
{
    if (_devices.empty())
    {
        std::cout << "No devices\n";
    }
    else
    {
        for (const auto& device : _devices)
        {
            std::cout << device -> getStatus();
        }
    }
    
    std::cout << "Total devices: " << _devices.size() << "\n";
    
    int onCnt = 0;
    for (const auto& device : _devices)
    {
        if (device -> isOn())
        {
            onCnt++;
        }
    }
    std::cout << "Active devices: " << onCnt << "\n";
}


SmartDevice* HomeHub::_findDeviceById(int id)
{
    auto it = std::find_if(_devices.begin(), _devices.end(),
        [id](const std::unique_ptr<SmartDevice>& device)
        {
            return device -> getId() == id;
        });
    
    return (it != _devices.end()) ? it -> get() : nullptr;
}


void HomeHub::sendCommand(int id, const std::string& cmd)
{
    SmartDevice* device = _findDeviceById(id);
    
    if (!device)
    {
        std::cout << "\nERROR: Device with ID:" << id << " not found\n";
        std::cout << "Available IDs: ";
        for (const auto& device : _devices)
        {
            std::cout << device -> getId() << " ";
        }
        std::cout << "\n";
        return;
    }
    
    if (cmd == "on")
    {
        device -> turnOn();
    }
    else if (cmd == "off")
    {
        device -> turnOff();
    }
    else if (cmd == "status")
    {
        std::cout << device -> getStatus();
    }
    else
    {
        try
        {
            device -> configure(cmd);
        }
        catch (const std::exception& e)
        {
            std::cout << "ERROR: " << e.what() << "\n";
        }
    }
}