#ifndef RECORD_HPP
#define RECORD_HPP

#include <cstddef>
#include <string>

class Record
{
public:
    virtual ~Record() = default;
    virtual std::string toString() const = 0;
    virtual std::string type() const = 0;
    virtual void serialize(void* buffer, size_t& offset) const = 0;
    virtual void deserialize(const void* buffer, size_t& offset) = 0;
};

#endif