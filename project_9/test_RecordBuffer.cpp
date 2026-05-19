
#include <catch2/catch_test_macros.hpp>
#include "RecordBuffer.hpp"
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <utility>

TEST_CASE("Construction and alignment", "[RecordBuffer]") {
    RecordBuffer buf(1024, true);
    REQUIRE(buf.capacity() == 1024);
    REQUIRE(buf.size() == 0);
    REQUIRE(buf.memory() != nullptr);

    auto addr = reinterpret_cast<std::uintptr_t>(buf.memory());
    REQUIRE(addr % alignof(std::max_align_t) == 0);
}

TEST_CASE("Move constructor transfers ownership (zero-copy)", "[RecordBuffer]") {
    RecordBuffer src(512, false);
    auto origMemory = src.memory();
    auto origCap = src.capacity();

    RecordBuffer dst(std::move(src));
    REQUIRE(dst.memory() == origMemory);
    REQUIRE(dst.capacity() == origCap);
    REQUIRE(src.memory() == nullptr);
    REQUIRE(src.size() == 0);
}

TEST_CASE("Move assignment transfers ownership", "[RecordBuffer]") {
    RecordBuffer buf1(256, true);
    RecordBuffer buf2(128, false);
    auto buf2Ptr = buf2.memory();

    buf1 = std::move(buf2);
    REQUIRE(buf1.memory() == buf2Ptr);
    REQUIRE(buf2.memory() == nullptr);
}

TEST_CASE("Copy constructor performs deep copy", "[RecordBuffer]") {
    RecordBuffer src(200, true);
    std::memcpy(static_cast<void*>(const_cast<void*>(src.memory())), "TEST_memory", 10);

    RecordBuffer dst(src);
    REQUIRE(dst.memory() != src.memory());
    REQUIRE(dst.capacity() == src.capacity());
    REQUIRE(std::memcmp(dst.memory(), "TEST_memory", 10) == 0); 
}

TEST_CASE("Copy assignment uses copy-and-swap", "[RecordBuffer]") {
    RecordBuffer buf1(300, false);
    RecordBuffer buf2(100, true);
    std::memcpy(static_cast<void*>(const_cast<void*>(buf2.memory())), "COPY_ME", 8);

    buf1 = buf2;
    REQUIRE(buf1.memory() != buf2.memory());
    REQUIRE(buf1.capacity() == buf2.capacity());
    REQUIRE(std::memcmp(buf1.memory(), "COPY_ME", 8) == 0);
}

TEST_CASE("clear frees memory and clears state", "[RecordBuffer]") {
    RecordBuffer buf(4096, true);
    auto ptr = buf.memory();
    REQUIRE(ptr != nullptr);
    REQUIRE(buf.capacity() == 4096);

    buf.clear();
    REQUIRE(buf.memory() == nullptr);
    REQUIRE(buf.size() == 0);
}

TEST_CASE("Self-assignment is safe", "[RecordBuffer]") {
    RecordBuffer buf(512, true);
    std::memcpy(static_cast<void*>(const_cast<void*>(buf.memory())), "SELF_TEST", 10);
    auto origPtr = buf.memory();

    buf = buf;
    REQUIRE(buf.memory() == origPtr);
    REQUIRE(std::memcmp(buf.memory(), "SELF_TEST", 10) == 0);

    buf = std::move(buf);
    REQUIRE(buf.memory() != nullptr);
    REQUIRE(buf.memory() == origPtr);
}

TEST_CASE("Friend swap exchanges states correctly", "[RecordBuffer]") {
    RecordBuffer lhs(100, false);
    RecordBuffer rhs(200, true);
    auto lhsPtr = lhs.memory();
    auto rhsPtr = rhs.memory();

    swap(lhs, rhs);
    REQUIRE(lhs.memory() == rhsPtr);
    REQUIRE(rhs.memory() == lhsPtr);
    REQUIRE(lhs.capacity() == 200);
    REQUIRE(rhs.capacity() == 100);
}

TEST_CASE("Alignment disabled still allocates valid memory", "[RecordBuffer]") {
    RecordBuffer buf(64, false);
    REQUIRE(buf.memory() != nullptr);
    REQUIRE(buf.capacity() == 64);
    std::memset(static_cast<void*>(const_cast<void*>(buf.memory())), 0xAA, 64);
    REQUIRE(std::memcmp(buf.memory(), "\xAA", 64) == 0);
}