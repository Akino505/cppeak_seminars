#include "HomeHub.hpp"
#include "SecurityCamera.hpp"
#include "SmartLight.hpp"
#include "Thermostat.hpp"
#include <iostream>

int main()
{
    HomeHub hub;

    hub.addDevice(std::make_unique<SmartLight>(1, "lamp in bedroom"));
    hub.addDevice(std::make_unique<SmartLight>(2, "lamp in kitchen", 70));
    hub.addDevice(std::make_unique<SecurityCamera>(3, "camera outside"));
    hub.addDevice(std::make_unique<SecurityCamera>(4, "camera in room",
                                                   CameraMode::CONTINUOUS));
    hub.addDevice(std::make_unique<Thermostat>(5, "thermostat in bedroom"));
    hub.addDevice(
        std::make_unique<Thermostat>(6, "thermostat in kitchen", -12.3));

    // (all off)
    std::cout << "\n----- INITIAL REPORT -----\n";
    hub.generateReport();

    std::cout << "\n----- SENDING COMMANDS -----\n";
    hub.sendCommand(2, "on");                // lamp2 on
    hub.sendCommand(3, "on");                // cam1 on
    hub.sendCommand(6, "on");                // temp2 on
    hub.sendCommand(1, "brightness=80");     // lamp1 config
    hub.sendCommand(4, "mode=motion");       // cam2 config
    hub.sendCommand(5, "temperature=22.5");  // temp1 config

    std::cout << "\n----- INVALID ID TEST -----\n";
    hub.sendCommand(99, "on");
    hub.sendCommand(7, "off");
    hub.sendCommand(8, "brightness=50");

    std::cout << "\n----- ACTIVATE ALL -----\n";
    hub.activateAll();

    // (all on)
    std::cout << "\n----- FINAL REPORT -----\n";
    hub.generateReport();

    return 0;
}