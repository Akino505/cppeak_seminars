#ifndef RECORD_BUFFER_HPP
#define RECORD_BUFFER_HPP
#include <cstddef>

class RecordBuffer
{
public:
    RecordBuffer(size_t capacity, bool aligned);
    ~RecordBuffer();
    RecordBuffer(const RecordBuffer& other);             // CC
    RecordBuffer& operator=(const RecordBuffer& other);  // CAO
    RecordBuffer(RecordBuffer& other);                   // MC
    RecordBuffer& operator=(RecordBuffer& other);        // MAO
    void clear();
    // Getters
    size_t capacity() const { return _capacity; };
    size_t size() const { return _size; };
    const void* memory() const { return _memory; };

private:
    void* _memory;
    void* _rawAlloc;
    bool _aligned;
    size_t _size;
    size_t _capacity;
    void swap(RecordBuffer& lhs, RecordBuffer& rhs) noexcept;
};

#endif