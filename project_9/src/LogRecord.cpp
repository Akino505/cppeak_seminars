#include "LogRecord.hpp"

LogRecord::LogRecord(const std::string& event): event_(event)
{
    std::cout << "[LOG] LogRecord created: event=\"" << event_ << "\"\n";
}

std::string LogRecord::toString() const { return "Log"; }

std::string LogRecord::type() const { return event_; }

void LogRecord::serialize(void* buffer, size_t& offset) const
{
    uint32_t len = static_cast<uint32_t>(event_.size());
    std::memcpy(static_cast<char*>(buffer) + offset, &len, sizeof(len));
    offset += sizeof(len);
    std::memcpy(static_cast<char*>(buffer) + offset, event_.c_str(), len);
    offset += len;
}

void LogRecord::deserialize(const void* buffer, size_t& offset)
{
    uint32_t len = 0;
    std::memcpy(&len, static_cast<const char*>(buffer) + offset, sizeof(len));
    offset += sizeof(len);
    event_.assign(static_cast<const char*>(buffer) + offset, len);
    offset += len;
}