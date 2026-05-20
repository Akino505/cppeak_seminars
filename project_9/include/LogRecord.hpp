#ifndef LOG_RECORD_HPP
#define LOG_RECORD_HPP

#include "Record.hpp"
#include <cstdint>
#include <cstring>
#include <iostream>

class LogRecord: public Record
{
public:
    LogRecord(const std::string& event);
    std::string toString() const override;
    std::string type() const override;
    void serialize(void* buffer, size_t& offset) const override;
    void deserialize(const void* buffer, size_t& offset) override;

private:
    std::string event_;
};

#endif