#ifndef TABLE_HPP
#define TABLE_HPP

#include "Record.hpp"
#include "RecordBuffer.hpp"
#include <functional>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

class Table
{
public:
    Table();
    explicit Table(size_t bufferCapacity);
    ~Table() = default;
    Table(const Table&) = default;
    Table& operator=(const Table&) = default;
    Table(Table&&) = default;
    Table& operator=(Table&&) = default;

    void insert(std::shared_ptr<Record> record);
    void optimize(std::function<void(RecordBuffer&&)> callback);
    std::string dump() const;
    void printLog() const;

    size_t size() const { return records_.size(); }
    const RecordBuffer& getBuffer() const { return buffer_; }

private:
    RecordBuffer buffer_;
    std::vector<std::shared_ptr<Record>> records_;

    std::string makeAsciiTable() const;
};

#endif