#include "RecordBuffer.hpp"
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <memory>
#include <utility>

RecordBuffer::RecordBuffer(size_t capacity, bool aligned)
    : _capacity(capacity), _aligned(aligned)
{
    size_t allocSize = _capacity + alignof(std::max_align_t);
    _rawAlloc = new uint8_t[allocSize];
    void* ptr = _rawAlloc;
    size_t space = allocSize;
    if(_aligned && std::align(alignof(std::max_align_t), _capacity, ptr, space))
        _memory = ptr;
    else
        _memory = _rawAlloc;
    std::cout << "[LOG] RecordBuffer alloc: " << _capacity
              << " bytes aligned\n";
}

RecordBuffer::~RecordBuffer()
{
    if(_rawAlloc)
    {
        delete[] _rawAlloc;
        std::cout << "[LOG] RecordBuffer dealloc\n";
    }
}

RecordBuffer::RecordBuffer(const RecordBuffer& other)  // CC
    : _capacity(other._capacity), _aligned(other._aligned), _memory(nullptr),
      _size(0), _rawAlloc(nullptr)
{
    if(!other._rawAlloc)
        return;
    size_t allocSize = _capacity + alignof(std::max_align_t);
    std::unique_ptr<uint8_t[]> newBuff(new uint8_t[allocSize]);
    void* ptr = newBuff.get();
    size_t space = allocSize;
    if(_aligned && std::align(alignof(std::max_align_t), _capacity, ptr, space))
        _memory = ptr;
    else
        _memory = newBuff.get();
    if(other._size > 0)
        std::memcpy(_memory, other._memory, other._size);
    _size = other._size;
    _rawAlloc = newBuff.release();
}

void swap(RecordBuffer& lhs, RecordBuffer& rhs) noexcept
{
    std::swap(lhs._memory, rhs._memory);
    std::swap(lhs._aligned, rhs._aligned);
    std::swap(lhs._rawAlloc, rhs._rawAlloc);
    std::swap(lhs._capacity, rhs._capacity);
    std::swap(lhs._size, rhs._size);
}

RecordBuffer& RecordBuffer::operator=(const RecordBuffer& other)  // CAO
{
    if(this != &other)
    {
        RecordBuffer newBuff(other);
        swap(*this, newBuff);
    }
    return *this;
}

RecordBuffer::RecordBuffer(RecordBuffer&& other) noexcept  // MC
    : _aligned(other._aligned), _capacity(other._capacity),
      _memory(other._memory), _rawAlloc(other._rawAlloc), _size(other._size)
{
    other._memory = nullptr;
    other._rawAlloc = nullptr;
    other._size = 0;
    other._capacity = 0;
    other._aligned = false;
}

RecordBuffer& RecordBuffer::operator=(RecordBuffer&& other) noexcept  // MAO
{
    if(this != &other)
    {
        RecordBuffer newBuff(std::move(other));
        swap(*this, newBuff);
    }
    return *this;
}

void RecordBuffer::clear()
{
    if(_rawAlloc)
    {
        delete[] _rawAlloc;
        std::cout << "[LOG] RecordBuffer dealloc\n";
    }
    _memory = nullptr;
    _aligned = false;
    _capacity = 0;
    _size = 0;
    _rawAlloc = nullptr;
}