#include "ConfigStore.hpp"
#include "ConfigValidator.hpp"
#include "Constraint.hpp"
#include "Exception.hpp"
#include <catch2/catch_test_macros.hpp>
#include <span>
#include <string>
#include <vector>

TEST_CASE("ConfigValidator::validate enforces constraints correctly")
{

    auto makeValidator = [](const std::vector<Constraint>& rules)
    { return ConfigValidator(std::span<const Constraint>{rules}); };

    SECTION("Passes when all constraints are satisfied (double)")
    {
        ConfigStore store;
        store.set("timeout.sec", 5.5);

        const std::vector<Constraint> rules = {
            {"timeout.sec", typeid(double), false, 1.0, 10.0}};

        REQUIRE_NOTHROW(makeValidator(rules).validate(store));
    }

    SECTION("Passes when all constraints are satisfied (int)")
    {
        ConfigStore store;
        store.set("server.port", 8080);

        const std::vector<Constraint> rules = {
            {"server.port", typeid(int), true, 1024, 65535}};

        REQUIRE_NOTHROW(makeValidator(rules).validate(store));
    }

    SECTION("Throws MissingRequiredFieldException for absent required key")
    {
        ConfigStore store;
        const std::vector<Constraint> rules = {
            {"server.port", typeid(int), true, std::nullopt, std::nullopt}};

        REQUIRE_THROWS_AS(makeValidator(rules).validate(store),
                          MissingRequiredFieldException);
    }

    SECTION("Passes silently when optional key is missing")
    {
        ConfigStore store;
        const std::vector<Constraint> rules = {
            {"debug.mode", typeid(bool), false, std::nullopt, std::nullopt}};

        REQUIRE_NOTHROW(makeValidator(rules).validate(store));
    }

    SECTION("Throws InvalidKeyTypeException: string instead of int")
    {
        ConfigStore store;
        store.set("port", std::string("8080"));

        const std::vector<Constraint> rules = {
            {"port", typeid(int), true, std::nullopt, std::nullopt}};

        REQUIRE_THROWS_AS(makeValidator(rules).validate(store),
                          InvalidKeyTypeException);
    }

    SECTION("Throws InvalidKeyTypeException: int instead of bool")
    {
        ConfigStore store;
        store.set("enabled", 1);

        const std::vector<Constraint> rules = {
            {"enabled", typeid(bool), true, std::nullopt, std::nullopt}};

        REQUIRE_THROWS_AS(makeValidator(rules).validate(store),
                          InvalidKeyTypeException);
    }

    SECTION("Throws ConstraintViolationException: int value < min")
    {
        ConfigStore store;
        store.set("port", 80);

        const std::vector<Constraint> rules = {
            {"port", typeid(int), true, 1024, 65535}};

        REQUIRE_THROWS_AS(makeValidator(rules).validate(store),
                          ConstraintViolationException);
    }

    SECTION("Throws ConstraintViolationException: int value > max")
    {
        ConfigStore store;
        store.set("port", 70000);

        const std::vector<Constraint> rules = {
            {"port", typeid(int), true, 1024, 65535}};

        REQUIRE_THROWS_AS(makeValidator(rules).validate(store),
                          ConstraintViolationException);
    }

    SECTION("Throws ConstraintViolationException: double value < min")
    {
        ConfigStore store;
        store.set("timeout", 0.5);

        const std::vector<Constraint> rules = {
            {"timeout", typeid(double), true, 1.0, 10.0}};

        REQUIRE_THROWS_AS(makeValidator(rules).validate(store),
                          ConstraintViolationException);
    }

    SECTION("Throws ConstraintViolationException: double value > max")
    {
        ConfigStore store;
        store.set("timeout", 15.0);

        const std::vector<Constraint> rules = {
            {"timeout", typeid(double), true, 1.0, 10.0}};

        REQUIRE_THROWS_AS(makeValidator(rules).validate(store),
                          ConstraintViolationException);
    }

    SECTION("Bool validation: passes when type matches (no range check)")
    {
        ConfigStore store;
        store.set("debug", true);

        const std::vector<Constraint> rules = {
            {"debug", typeid(bool), true, std::nullopt, std::nullopt}};

        REQUIRE_NOTHROW(makeValidator(rules).validate(store));
    }

    SECTION("Fail-fast: stops at first validation failure")
    {
        ConfigStore store;
        store.set("port", 80);    // Нарушает min (int)
        store.set("ssl", "yes");  // Нарушает тип

        const std::vector<Constraint> rules = {
            {"port", typeid(int), true, 1024, 65535},
            {"ssl", typeid(bool), true, std::nullopt, std::nullopt}};

        auto validator = makeValidator(rules);
        try
        {
            validator.validate(store);
            FAIL("Expected ConstraintViolationException");
        }
        catch(const ConstraintViolationException& e)
        {
            REQUIRE(std::string(e.what()).find("port") != std::string::npos);
        }
    }
}