#include "UserRecord.hpp"

UserRecord::UserRecord(int id, const std::string& name): id_(id), name_(name)
{
    std::cout << "[LOG] UserRecord created: id=" << id_ << ", name=\"" << name_
              << "\"\n";
}

std::string UserRecord::toString() const { return "User"; }

std::string UserRecord::type() const
{
    return std::to_string(id_) + "\t" + name_;
}

void UserRecord::serialize(void* buffer, size_t& offset) const
{
    std::memcpy(static_cast<char*>(buffer) + offset, &id_, sizeof(id_));
    offset += sizeof(id_);
    uint32_t len = static_cast<uint32_t>(name_.size());
    std::memcpy(static_cast<char*>(buffer) + offset, &len, sizeof(len));
    offset += sizeof(len);
    std::memcpy(static_cast<char*>(buffer) + offset, name_.c_str(), len);
    offset += len;
}

void UserRecord::deserialize(const void* buffer, size_t& offset)
{
    std::memcpy(&id_, static_cast<const char*>(buffer) + offset, sizeof(id_));
    offset += sizeof(id_);
    uint32_t len = 0;
    std::memcpy(&len, static_cast<const char*>(buffer) + offset, sizeof(len));
    offset += sizeof(len);
    name_.assign(static_cast<const char*>(buffer) + offset, len);
    offset += len;
}