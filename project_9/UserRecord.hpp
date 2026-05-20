#ifndef USER_RECORD_HPP
#define USER_RECORD_HPP

#include "Record.hpp"
#include <cstdint>
#include <cstring>
#include <iostream>

class UserRecord: public Record
{
public:
    UserRecord(int id, const std::string& name);
    std::string toString() const override;
    std::string type() const override;
    void serialize(void* buffer, size_t& offset) const override;
    void deserialize(const void* buffer, size_t& offset) override;

private:
    int id_;
    std::string name_;
};

#endif