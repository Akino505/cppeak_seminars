#include "LogRecord.hpp"
#include "Table.hpp"
#include "UserRecord.hpp"
#include <iostream>
#include <memory>

int main()
{
    Table table;

    table.insert(std::make_shared<UserRecord>(1, "Alice"));
    table.insert(std::make_shared<LogRecord>("LOGIN"));

    std::cout << "Table batch insert complete.\n";

    std::cout << "Copying table...\n";
    Table copy = table;
    copy.printLog();

    std::cout << "Moving buffer...\n";
    table.optimize(
        [](RecordBuffer&& buf)
        {
            std::cout << "  [MOVE] RecordBuffer transferred. Original size="
                      << buf.capacity() << "\n";
        });

    std::cout << table.dump();

    std::cout << "Destructors: Ref count drops to 0 -> memory freed.\n";

    return 0;
}