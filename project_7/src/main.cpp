#include "SecurityCamera.hpp"
#include "SmartLight.hpp"
#include "Thermostat.hpp"
#include <string_view>
#include <iostream>

auto safe_configure = [](auto& device, std::string param) {
    try {
        device.configure(param); 
    } catch (const std::exception& e) {
        std::cout << "ERROR: " << e.what() << "\n";
    }
};


int main()
{
    SmartLight lamp1(1, "lamp in bedroom");
    SmartLight lamp2(2, "lamp in kitchen", 70);
    SecurityCamera cam1(3, "camera outside");
    SecurityCamera cam2(4, "camera in room", CameraMode::CONTINUOUS);
    Thermostat temp1(5, "thermostat in bedroom");
    Thermostat temp2(6, "thermostat in kitchen", -12.3);
    std::string statL1 = lamp1.getStatus();
    std::string statL2 = lamp2.getStatus();
    std::string statC1 = cam1.getStatus();
    std::string statC2 = cam2.getStatus();
    std::string statT1 = temp1.getStatus();
    std::string statT2 = temp2.getStatus();

    std::cout << "-----FIRST STATUS-----" << "\n";
    std::cout << statL1 << statL2 << statC1 << statC2 << statT1 << statT2;
    lamp2.turnOn();
    cam1.turnOn();
    temp2.turnOn();
    statL2 = lamp2.getStatus();
    statC1 = cam1.getStatus();
    statT2 = temp2.getStatus();

    std::cout << "-----ON STATUS-----" << "\n";
    std::cout << statL2 << statC1 << statT2;
    lamp1.turnOn();
    cam2.turnOn();
    temp1.turnOn();

    std::cout << "-----ERRORS-----" << "\n";
    safe_configure(lamp2, "brightneSs=90");
    safe_configure(lamp2, "brightness=am9");
    safe_configure(lamp2, "brightness=1000");
    safe_configure(cam2, "modE=asdas");
    safe_configure(cam2, "mode=asdas");
    safe_configure(temp2, "temperaturE=12.0");
    safe_configure(temp2, "temperature=a12.0");
    safe_configure(temp2, "temperature=100.0");
    safe_configure(temp2, "temperature=-120.0");
    lamp1.configure("brightness=10");
    cam1.configure("mode=continuous");
    temp1.configure("temperature=11.1123213");
    statL1 = lamp1.getStatus();
    statL2 = lamp2.getStatus();
    statC1 = cam1.getStatus();
    statC2 = cam2.getStatus();
    statT1 = temp1.getStatus();
    statT2 = temp2.getStatus();
    
    std::cout << "-----AFTER CONFIG STATUS-----" << "\n";
    std::cout << statL1 << statL2 << statC1 << statC2 << statT1 << statT2;
}
