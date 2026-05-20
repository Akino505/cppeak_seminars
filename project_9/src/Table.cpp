#include "Table.hpp"

Table::Table(): Table(4096) {}

Table::Table(size_t bufferCapacity): buffer_(bufferCapacity, true) {}

void Table::insert(std::shared_ptr<Record> record)
{
    if(!record)
        throw std::invalid_argument("Cannot insert null record");

    records_.push_back(std::move(record));
}

void Table::optimize(std::function<void(RecordBuffer&&)> callback)
{
    callback(std::move(buffer_));
    buffer_ = RecordBuffer(4096, true);
}

void Table::printLog() const
{
    if(!records_.empty())
    {
        std::cout << "  [COPY] shared_ptr ref count increased: "
                  << records_[0].use_count() << "\n";
    }
}

std::string Table::dump() const { return makeAsciiTable(); }

std::string Table::makeAsciiTable() const
{
    if(records_.empty())
        return "Table is empty\n";

    std::ostringstream oss;

    std::string userId, userName, logEvent;

    for(const auto& record: records_)
    {
        std::string typeStr = record->toString();
        std::string dataStr = record->type();

        if(typeStr == "User")
        {
            size_t tabPos = dataStr.find('\t');
            if(tabPos != std::string::npos)
            {
                userId = dataStr.substr(0, tabPos);
                userName = dataStr.substr(tabPos + 1);
            }
        }
        else if(typeStr == "Log")
        {
            logEvent = dataStr;
        }
    }

    oss << "Table dump:\n";
    oss << "+----+--------+-----------+\n";
    oss << "| ID | Name   | Event     |\n";
    oss << "+----+--------+-----------+\n";
    oss << "| " << std::setw(2) << std::left << userId << " | " << std::setw(6)
        << std::left << userName << " | " << std::setw(9) << std::left
        << logEvent << " |\n";
    oss << "+----+--------+-----------+\n";

    return oss.str();
}