#include "UserRecord.hpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

// ─────────────────────────────────────────────────────────────
// Конструктор и базовые методы
// ─────────────────────────────────────────────────────────────
TEST_CASE("UserRecord constructor")
{
    UserRecord rec(1, "Alina");
    REQUIRE(rec.toString() == "User");
    REQUIRE(rec.type() == "1\tAlina");
}

TEST_CASE("UserRecord const methods")
{
    const UserRecord rec(2, "Bob");
    REQUIRE(rec.toString() == "User");
    REQUIRE(rec.type() == "2\tBob");
}

// ─────────────────────────────────────────────────────────────
// Сериализация
// ─────────────────────────────────────────────────────────────
TEST_CASE("UserRecord serialize")
{
    UserRecord rec(42, "Test");
    std::vector<uint8_t> buffer(256);
    size_t offset = 0;
    rec.serialize(buffer.data(), offset);

    REQUIRE(offset == sizeof(int) + sizeof(uint32_t) + 4);

    int id;
    std::memcpy(&id, buffer.data(), sizeof(int));
    REQUIRE(id == 42);

    uint32_t len;
    std::memcpy(&len, buffer.data() + sizeof(int), sizeof(uint32_t));
    REQUIRE(len == 4);

    std::string name(
        reinterpret_cast<char*>(buffer.data() + sizeof(int) + sizeof(uint32_t)),
        len);
    REQUIRE(name == "Test");
}

// ─────────────────────────────────────────────────────────────
// Десериализация
// ─────────────────────────────────────────────────────────────
TEST_CASE("UserRecord deserialize")
{

    std::vector<uint8_t> buffer(256);
    int originalId = 99;
    std::string originalName = "Alina";
    size_t offset = 0;
    std::memcpy(buffer.data() + offset, &originalId, sizeof(int));
    offset += sizeof(int);
    uint32_t len = static_cast<uint32_t>(originalName.size());
    std::memcpy(buffer.data() + offset, &len, sizeof(uint32_t));
    offset += sizeof(uint32_t);
    std::memcpy(buffer.data() + offset, originalName.c_str(), len);
    offset += len;

    UserRecord rec(0, "");
    size_t readOffset = 0;
    rec.deserialize(buffer.data(), readOffset);

    REQUIRE(readOffset == offset);
    REQUIRE(rec.type() == "99\tAlina");
}

// ─────────────────────────────────────────────────────────────
// Сериализация -> десериализация (кто это читает?)
// ─────────────────────────────────────────────────────────────
TEST_CASE("UserRecord round-trip")
{
    UserRecord original(7, "Pavel");
    std::vector<uint8_t> buffer(256);
    size_t writeOffset = 0;
    original.serialize(buffer.data(), writeOffset);

    UserRecord restored(0, "");
    size_t readOffset = 0;
    restored.deserialize(buffer.data(), readOffset);

    REQUIRE(readOffset == writeOffset);
    REQUIRE(restored.type() == original.type());
}