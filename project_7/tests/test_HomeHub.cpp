#include "HomeHub.hpp"
#include "SmartLight.hpp"
#include "Thermostat.hpp"
#include "SecurityCamera.hpp"
#include <catch2/catch_test_macros.hpp>
#include <memory>

TEST_CASE("HomeHub: add device successfully.", "[hub]")
{
    HomeHub hub;
    auto light = std::make_unique<SmartLight>(1, "Light");
    
    REQUIRE_NOTHROW(hub.addDevice(std::move(light)));
}

TEST_CASE("HomeHub: reject duplicate ID.", "[hub]")
{
    HomeHub hub;
    hub.addDevice(std::make_unique<SmartLight>(1, "Light1"));
    
    auto light2 = std::make_unique<SmartLight>(1, "Light2");
    REQUIRE_NOTHROW(hub.addDevice(std::move(light2)));
}

TEST_CASE("HomeHub: send 'on' command.", "[hub]")
{
    HomeHub hub;
    hub.addDevice(std::make_unique<SmartLight>(1, "Light"));
    
    REQUIRE_NOTHROW(hub.sendCommand(1, "on"));
}

TEST_CASE("HomeHub: send command to non-existing device.", "[hub]")
{
    HomeHub hub;
    hub.addDevice(std::make_unique<SmartLight>(1, "Light"));
    
    REQUIRE_NOTHROW(hub.sendCommand(999, "on"));
}

TEST_CASE("HomeHub: generate report.", "[hub]")
{
    HomeHub hub;
    hub.addDevice(std::make_unique<SmartLight>(1, "Light"));
    hub.addDevice(std::make_unique<Thermostat>(2, "Thermo"));
    
    REQUIRE_NOTHROW(hub.generateReport());
}

TEST_CASE("HomeHub: activate all devices.", "[hub]")
{
    HomeHub hub;
    hub.addDevice(std::make_unique<SmartLight>(1, "Light"));
    hub.addDevice(std::make_unique<SecurityCamera>(2, "Camera"));
    
    REQUIRE_NOTHROW(hub.activateAll());
}

TEST_CASE("HomeHub: deactivate all devices.", "[hub]")
{
    HomeHub hub;
    hub.addDevice(std::make_unique<SmartLight>(1, "Light"));
    
    hub.activateAll();
    REQUIRE_NOTHROW(hub.deactivateAll());
}