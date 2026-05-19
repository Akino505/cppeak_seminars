#include "ConfigStore.hpp"
#include <any>
#include <catch2/catch_test_macros.hpp>
#include <optional>
#include <string>

TEST_CASE("ConfigStore manages settings correctly")
{

    SECTION("Construction and initial size")
    {
        ConfigStore storeDefault;
        REQUIRE(storeDefault.size() == 0);

        ConfigStore storeCustom(32);
        REQUIRE(storeCustom.size() == 0);
    }

    SECTION("Set and retrieve heterogeneous types")
    {
        ConfigStore store;
        store.set("server.port", 8080);
        store.set("server.host", std::string("localhost"));
        store.set("debug.enabled", true);
        store.set("timeout.sec", 5.5);

        REQUIRE(store.size() == 4);

        // int
        auto port = store.get("server.port");
        REQUIRE(port.has_value());
        REQUIRE(std::any_cast<int>(port->value) == 8080);
        REQUIRE(port->key == "server.port");

        // std::string
        auto host = store.get("server.host");
        REQUIRE(host.has_value());
        REQUIRE(std::any_cast<std::string>(host->value) == "localhost");

        // bool
        auto debug = store.get("debug.enabled");
        REQUIRE(debug.has_value());
        REQUIRE(std::any_cast<bool>(debug->value) == true);

        // double
        auto timeout = store.get("timeout.sec");
        REQUIRE(timeout.has_value());
        REQUIRE(std::any_cast<double>(timeout->value) == 5.5);
    }

    SECTION("Missing key returns std::nullopt")
    {
        ConfigStore store;
        store.set("exists", 42);

        auto missing = store.get("does_not_exist");
        REQUIRE_FALSE(missing.has_value());
        REQUIRE(missing == std::nullopt);
    }

    SECTION("Overwriting existing key updates value, size stays same")
    {
        ConfigStore store;
        store.set("key", 10);
        REQUIRE(std::any_cast<int>(store.get("key")->value) == 10);
        REQUIRE(store.size() == 1);

        store.set("key", 20);
        REQUIRE(std::any_cast<int>(store.get("key")->value) == 20);
        REQUIRE(store.size() == 1);
    }

    SECTION("Type mismatch throws std::bad_any_cast")
    {
        ConfigStore store;
        store.set("version", std::string("1.0"));
        auto opt = store.get("version");
        REQUIRE_THROWS_AS(std::any_cast<int>(opt->value), std::bad_any_cast);
        REQUIRE(std::any_cast<std::string>(opt->value) == "1.0");
    }

    SECTION("Const data() access for validation")
    {
        ConfigStore store;
        store.set("a", 1);
        store.set("b", 2.0);

        const auto& internalMap = store.data();
        REQUIRE(internalMap.size() == 2);
        REQUIRE(internalMap.count("a") == 1);
        REQUIRE(internalMap.count("b") == 1);
    }
}