#include "SecurityCamera.hpp"
#include <catch2/catch_test_macros.hpp>
#include <stdexcept>

TEST_CASE("SecurityCamera: default initialisasion.", "[device][camera]")
{
    SecurityCamera cam(1, "Camera");
    CHECK(!cam.isOn());
    CHECK(cam.getId() == 1);
    CHECK(cam.getName() == "Camera");
    CHECK(cam.getMode() == CameraMode::MOTION);
}

TEST_CASE("SecurityCamera: isOn.", "[isOn][camera]")
{
    SecurityCamera cam(1, "Camera");
    cam.turnOn();
    CHECK(cam.isOn());
    cam.turnOff();
    CHECK(!cam.isOn());
}

TEST_CASE("SecurityCamera: configure with validation.", "[configure][camera]")
{
    SecurityCamera cam(1, "Camera");
    CHECK_NOTHROW(cam.configure("mode=motion"));
    cam.configure("mode=continuous");
    CHECK(cam.getMode() == CameraMode::CONTINUOUS);
    CHECK(!cam.isOn());
    cam.turnOn();
    CHECK_THROWS_AS(cam.configure("wrong_key=motion"), std::invalid_argument);
    CHECK_THROWS_AS(cam.configure("mode=asd1"), std::invalid_argument);
}