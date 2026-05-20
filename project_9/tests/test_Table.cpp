#include "LogRecord.hpp"
#include "Table.hpp"
#include "UserRecord.hpp"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <sstream>

TEST_CASE("Table default constructor")
{
    Table table;
    REQUIRE(table.size() == 0);
    REQUIRE(table.getBuffer().capacity() == 4096);
}

TEST_CASE("Table constructor with custom capacity")
{
    Table table(2048);
    REQUIRE(table.size() == 0);
    REQUIRE(table.getBuffer().capacity() == 2048);
}

TEST_CASE("Table insert single record")
{
    Table table;
    auto user = std::make_shared<UserRecord>(1, "Alice");

    table.insert(user);

    REQUIRE(table.size() == 1);
}

TEST_CASE("Table insert multiple records")
{
    Table table;
    auto user1 = std::make_shared<UserRecord>(1, "Alice");
    auto user2 = std::make_shared<UserRecord>(2, "Bob");
    auto log1 = std::make_shared<LogRecord>("LOGIN");

    table.insert(user1);
    table.insert(user2);
    table.insert(log1);

    REQUIRE(table.size() == 3);
}

TEST_CASE("Table insert null record throws")
{
    Table table;
    std::shared_ptr<Record> nullRecord = nullptr;

    REQUIRE_THROWS_AS(table.insert(nullRecord), std::invalid_argument);
    REQUIRE(table.size() == 0);
}

TEST_CASE("Table dump empty")
{
    Table table;
    std::string dump = table.dump();

    REQUIRE(dump == "Table is empty\n");
}

TEST_CASE("Table dump with UserRecord only")
{
    Table table;
    auto user = std::make_shared<UserRecord>(42, "TestUser");
    table.insert(user);

    std::string dump = table.dump();

    REQUIRE(dump.find("42") != std::string::npos);
    REQUIRE(dump.find("TestUser") != std::string::npos);
    REQUIRE(dump.find("ID") != std::string::npos);
    REQUIRE(dump.find("Name") != std::string::npos);
    REQUIRE(dump.find("Event") != std::string::npos);
}

TEST_CASE("Table dump with LogRecord only")
{
    Table table;
    auto log = std::make_shared<LogRecord>("TEST_EVENT");
    table.insert(log);

    std::string dump = table.dump();

    REQUIRE(dump.find("TEST_EVENT") != std::string::npos);
    REQUIRE(dump.find("-") != std::string::npos);
}

TEST_CASE("Table dump mixed records")
{
    Table table;
    auto user = std::make_shared<UserRecord>(10, "Charlie");
    auto log = std::make_shared<LogRecord>("START");
    table.insert(user);
    table.insert(log);

    std::string dump = table.dump();

    REQUIRE(dump.find("10") != std::string::npos);
    REQUIRE(dump.find("Charlie") != std::string::npos);
    REQUIRE(dump.find("START") != std::string::npos);
}

TEST_CASE("Table copy constructor increases shared_ptr ref count")
{
    Table table;
    auto user = std::make_shared<UserRecord>(1, "Alice");
    table.insert(user);

    Table copy = table;

    REQUIRE(copy.size() == table.size());
    REQUIRE(copy.size() == 1);
}

TEST_CASE("Table copy assignment")
{
    Table table1;
    Table table2;

    auto user = std::make_shared<UserRecord>(5, "Eve");
    table1.insert(user);

    table2 = table1;

    REQUIRE(table2.size() == 1);
}

TEST_CASE("Table optimize moves buffer")
{
    Table table;
    auto user = std::make_shared<UserRecord>(1, "Alice");
    table.insert(user);

    size_t oldCapacity = table.getBuffer().capacity();

    bool callbackCalled = false;
    table.optimize(
        [&callbackCalled](RecordBuffer&& buf)
        {
            callbackCalled = true;
            REQUIRE(buf.capacity() > 0);
        });

    REQUIRE(callbackCalled);
    REQUIRE(table.getBuffer().capacity() == oldCapacity);
    REQUIRE(table.size() == 1);
}

TEST_CASE("Table optimize records preserved")
{
    Table table;
    auto user = std::make_shared<UserRecord>(100, "Preserved");
    auto log = std::make_shared<LogRecord>("KEEP");
    table.insert(user);
    table.insert(log);

    REQUIRE(table.size() == 2);

    table.optimize([](RecordBuffer&& buf) {});

    REQUIRE(table.size() == 2);
    std::string dump = table.dump();
    REQUIRE(dump.find("100") != std::string::npos);
    REQUIRE(dump.find("KEEP") != std::string::npos);
}

TEST_CASE("Table printLog does not throw")
{
    Table table;
    auto user = std::make_shared<UserRecord>(1, "Alice");
    table.insert(user);

    REQUIRE_NOTHROW(table.printLog());
}

TEST_CASE("Table printLog empty table")
{
    Table table;
    REQUIRE_NOTHROW(table.printLog());
}

TEST_CASE("Table dump format validation")
{
    Table table;
    auto user = std::make_shared<UserRecord>(123, "LongName");
    table.insert(user);

    std::string dump = table.dump();

    REQUIRE(dump.find('+') != std::string::npos);
    REQUIRE(dump.find('|') != std::string::npos);
    REQUIRE(dump.find('-') != std::string::npos);

    REQUIRE(dump.find("123") != std::string::npos);
    REQUIRE(dump.find("LongName") != std::string::npos);
}

TEST_CASE("Table multiple operations sequence")
{
    Table table;

    auto user1 = std::make_shared<UserRecord>(1, "First");
    auto user2 = std::make_shared<UserRecord>(2, "Second");
    table.insert(user1);
    table.insert(user2);
    REQUIRE(table.size() == 2);

    Table copy = table;
    REQUIRE(copy.size() == 2);

    table.optimize([](RecordBuffer&& buf) {});
    REQUIRE(table.size() == 2);
    REQUIRE(copy.size() == 2);

    std::string copyDump = copy.dump();
    REQUIRE(copyDump.find("First") != std::string::npos);
    REQUIRE(copyDump.find("Second") != std::string::npos);
}

TEST_CASE("Table const methods")
{
    const Table table;
    REQUIRE(table.size() == 0);
    REQUIRE_NOTHROW(table.dump());
    REQUIRE_NOTHROW(table.printLog());
    REQUIRE_NOTHROW(table.getBuffer());
}

TEST_CASE("Table many records")
{
    Table table;
    const int numRecords = 100;

    for(int i = 0; i < numRecords; ++i)
    {
        auto user = std::make_shared<UserRecord>(i, "User" + std::to_string(i));
        table.insert(user);
    }

    REQUIRE(table.size() == numRecords);

    std::string dump = table.dump();
    REQUIRE(dump.find("User99") != std::string::npos);
}

TEST_CASE("Table mixed records interleaved")
{
    Table table;

    table.insert(std::make_shared<UserRecord>(1, "Alice"));
    table.insert(std::make_shared<LogRecord>("FIRST"));
    table.insert(std::make_shared<UserRecord>(2, "Bob"));
    table.insert(std::make_shared<LogRecord>("SECOND"));
    table.insert(std::make_shared<UserRecord>(3, "Charlie"));

    REQUIRE(table.size() == 5);

    std::string dump = table.dump();
    REQUIRE(dump.find("Alice") != std::string::npos);
    REQUIRE(dump.find("Bob") != std::string::npos);
    REQUIRE(dump.find("Charlie") != std::string::npos);
    REQUIRE(dump.find("FIRST") != std::string::npos);
    REQUIRE(dump.find("SECOND") != std::string::npos);
}