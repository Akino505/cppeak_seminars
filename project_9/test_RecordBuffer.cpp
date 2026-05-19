
#include <catch2/catch_test_macros.hpp>
#include "RecordBuffer.hpp"
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <utility>
#include <iostream>

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
    auto orig_memory = src.memory();
    auto orig_cap = src.capacity();

    RecordBuffer dst(std::move(src));
    REQUIRE(dst.memory() == orig_memory);
    REQUIRE(dst.capacity() == orig_cap);
    REQUIRE(src.memory() == nullptr);
    REQUIRE(src.size() == 0);
}

TEST_CASE("Move assignment transfers ownership", "[RecordBuffer]") {
    RecordBuffer buf1(256, true);
    RecordBuffer buf2(128, false);
    auto buf2_ptr = buf2.memory();

    buf1 = std::move(buf2);
    REQUIRE(buf1.memory() == buf2_ptr);
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
    auto original_ptr = buf.memory();

    buf = buf;
    REQUIRE(buf.memory() == original_ptr);
    REQUIRE(std::memcmp(buf.memory(), "SELF_TEST", 10) == 0);

    buf = std::move(buf);
    REQUIRE(buf.memory() != nullptr);
    REQUIRE(buf.memory() == original_ptr);
}

TEST_CASE("Friend swap exchanges states correctly", "[RecordBuffer]") {
    RecordBuffer a(100, false);
    RecordBuffer b(200, true);
    auto a_ptr = a.memory();
    auto b_ptr = b.memory();

    swap(a, b);
    REQUIRE(a.memory() == b_ptr);
    REQUIRE(b.memory() == a_ptr);
    REQUIRE(a.capacity() == 200);
    REQUIRE(b.capacity() == 100);
}

TEST_CASE("Alignment disabled still allocates valid memory", "[RecordBuffer]") {
    RecordBuffer buf(64, false);
    REQUIRE(buf.memory() != nullptr);
    REQUIRE(buf.capacity() == 64);
    std::memset(static_cast<void*>(const_cast<void*>(buf.memory())), 0xAA, 64);
    REQUIRE(std::memcmp(buf.memory(), "\xAA", 64) == 0);
}