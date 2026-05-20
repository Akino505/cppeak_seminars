#include <catch2/catch_test_macros.hpp>
#include "RecordBuffer.hpp"
#include <cstdint>

namespace {
    constexpr size_t CAP = 256;
    bool isAligned(const void* p, size_t align) {
        return reinterpret_cast<std::uintptr_t>(p) % align == 0;
    }
}

// ─────────────────────────────────────────────────────────────
// Конструктор
// ─────────────────────────────────────────────────────────────
TEST_CASE("Constructor", "[RecordBuffer]") {
    RecordBuffer buf(CAP, true);
    REQUIRE(buf.capacity() == CAP);
    REQUIRE(buf.size() == 0);              // _size всегда 0
    REQUIRE(buf.memory() != nullptr);
    REQUIRE(isAligned(buf.memory(), alignof(std::max_align_t)));
}

// ─────────────────────────────────────────────────────────────
// Копирование (проверяем только метаданные, т.к. _size=0)
// ─────────────────────────────────────────────────────────────
TEST_CASE("Copy constructor", "[RecordBuffer]") {
    RecordBuffer original(CAP, true);
    RecordBuffer copy(original);
    
    REQUIRE(copy.capacity() == original.capacity());
    REQUIRE(copy.size() == original.size());  // оба = 0
    REQUIRE(copy.memory() != original.memory()); // разные адреса → deep copy
}

// ─────────────────────────────────────────────────────────────
// Присваивание
// ─────────────────────────────────────────────────────────────
TEST_CASE("Copy assignment", "[RecordBuffer]") {
    RecordBuffer a(100, false);
    RecordBuffer b(200, true);
    
    const void* oldA = a.memory();
    a = b;
    
    REQUIRE(a.capacity() == 200);
    REQUIRE(a.memory() != oldA);  // старый буфер освобождён
    REQUIRE(a.memory() != b.memory()); // deep copy
}

// ─────────────────────────────────────────────────────────────
// Перемещение
// ─────────────────────────────────────────────────────────────
TEST_CASE("Move constructor", "[RecordBuffer]") {
    RecordBuffer original(CAP, false);
    const void* origMem = original.memory();
    
    RecordBuffer moved(std::move(original));
    
    REQUIRE(moved.memory() == origMem);  // владение передано
    REQUIRE(original.memory() == nullptr); // источник обнулён
    REQUIRE(original.capacity() == 0);
}

TEST_CASE("Move assignment", "[RecordBuffer]") {
    RecordBuffer target(100, true);
    RecordBuffer source(200, false);
    const void* srcMem = source.memory();
    
    target = std::move(source);
    
    REQUIRE(target.memory() == srcMem);
    REQUIRE(source.memory() == nullptr);
}

// ─────────────────────────────────────────────────────────────
// swap
// ─────────────────────────────────────────────────────────────
TEST_CASE("swap", "[RecordBuffer]") {
    RecordBuffer a(100, true);
    RecordBuffer b(200, false);
    
    const void* memA = a.memory();
    const void* memB = b.memory();
    
    swap(a, b);
    
    REQUIRE(a.memory() == memB);
    REQUIRE(b.memory() == memA);
    REQUIRE(a.capacity() == 200);
    REQUIRE(b.capacity() == 100);
}

// ─────────────────────────────────────────────────────────────
// clear
// ─────────────────────────────────────────────────────────────
TEST_CASE("clear", "[RecordBuffer]") {
    RecordBuffer buf(CAP, true);
    REQUIRE(buf.memory() != nullptr);
    
    buf.clear();
    
    REQUIRE(buf.memory() == nullptr);
    REQUIRE(buf.capacity() == 0);
    REQUIRE(buf.size() == 0);
}

// ─────────────────────────────────────────────────────────────
// noexcept и type traits
// ─────────────────────────────────────────────────────────────
TEST_CASE("noexcept guarantees", "[RecordBuffer]") {
    STATIC_REQUIRE(std::is_nothrow_move_constructible<RecordBuffer>::value);
    STATIC_REQUIRE(std::is_nothrow_move_assignable<RecordBuffer>::value);
    
    RecordBuffer a(10, true), b(20, false);
    STATIC_REQUIRE(noexcept(swap(a, b)));
}

// ─────────────────────────────────────────────────────────────
// Self-operations safety
// ─────────────────────────────────────────────────────────────
TEST_CASE("Self-assignment safety", "[RecordBuffer]") {
    RecordBuffer buf(CAP, true);
    REQUIRE_NOTHROW(buf = buf);           // copy self-assign
    REQUIRE_NOTHROW(buf = std::move(buf)); // move self-assign
    REQUIRE_NOTHROW(swap(buf, buf));      // self-swap
    REQUIRE(buf.capacity() == CAP);       // объект остался валидным
}