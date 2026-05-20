#include "LogRecord.hpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

// ─────────────────────────────────────────────────────────────
// Конструктор и базовые методы
// ─────────────────────────────────────────────────────────────
TEST_CASE("LogRecord constructor")
{
    LogRecord rec("LOGIN");
    REQUIRE(rec.toString() == "Log");
    REQUIRE(rec.type() == "LOGIN");
}

TEST_CASE("LogRecord const methods")
{
    const LogRecord rec("LOGOUT");
    REQUIRE(rec.toString() == "Log");
    REQUIRE(rec.type() == "LOGOUT");
}

// ─────────────────────────────────────────────────────────────
// Сериализация
// ─────────────────────────────────────────────────────────────
TEST_CASE("LogRecord serialize")
{
    LogRecord rec("EVENT");
    std::vector<uint8_t> buffer(256);
    size_t offset = 0;
    rec.serialize(buffer.data(), offset);

    REQUIRE(offset == sizeof(uint32_t) + 5);

    uint32_t len;
    std::memcpy(&len, buffer.data(), sizeof(uint32_t));
    REQUIRE(len == 5);

    std::string event(reinterpret_cast<char*>(buffer.data() + sizeof(uint32_t)),
                      len);
    REQUIRE(event == "EVENT");
}

// ─────────────────────────────────────────────────────────────
// Десериализация
// ─────────────────────────────────────────────────────────────
TEST_CASE("LogRecord deserialize")
{
    std::vector<uint8_t> buffer(256);
    std::string originalEvent = "START";
    size_t offset = 0;
    uint32_t len = static_cast<uint32_t>(originalEvent.size());
    std::memcpy(buffer.data() + offset, &len, sizeof(uint32_t));
    offset += sizeof(uint32_t);
    std::memcpy(buffer.data() + offset, originalEvent.c_str(), len);
    offset += len;

    LogRecord rec("");
    size_t readOffset = 0;
    rec.deserialize(buffer.data(), readOffset);

    REQUIRE(readOffset == offset);
    REQUIRE(rec.type() == "START");
}

// ─────────────────────────────────────────────────────────────
// Сериализация -> десериализация (кто это читает?)
// ─────────────────────────────────────────────────────────────
TEST_CASE("LogRecord round-trip")
{
    LogRecord original("SHUTDOWN");
    std::vector<uint8_t> buffer(256);
    size_t writeOffset = 0;
    original.serialize(buffer.data(), writeOffset);

    LogRecord restored("");
    size_t readOffset = 0;
    restored.deserialize(buffer.data(), readOffset);

    REQUIRE(readOffset == writeOffset);
    REQUIRE(restored.type() == original.type());
}