#include "addTask.hpp"
#include "readFile.hpp"
#include <catch2/catch_test_macros.hpp>
#include <fstream>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>

void createTestFile(const std::string& filename, const std::string& content)
{
    std::ofstream file(filename);
    file << content;
    file.close();
}

TEST_CASE("Testing addTask function")
{

    std::unordered_map<int, std::tuple<std::string, int, bool>> tasks;
    std::priority_queue<std::tuple<int, int, std::string>> pq;

    SECTION("Add task successfully")
    {
        addTask(tasks, pq, 1, "Test task", 5);

        REQUIRE(tasks.size() == 1);
        REQUIRE(tasks.find(1) != tasks.end());

        auto [desc, prio, status] = tasks[1];
        REQUIRE(desc == "Test task");
        REQUIRE(prio == 5);
        REQUIRE(status == false);

        REQUIRE_FALSE(pq.empty());
    }

    SECTION("Reject task with invalid priority")
    {
        addTask(tasks, pq, 1, "Invalid", -1);
        REQUIRE(tasks.empty());

        addTask(tasks, pq, 2, "Invalid", 11);
        REQUIRE(tasks.empty());
    }

    SECTION("Reject task with duplicate ID")
    {
        addTask(tasks, pq, 1, "First", 5);
        addTask(tasks, pq, 1, "Second", 3);

        REQUIRE(tasks.size() == 1);
        auto [desc, prio, status] = tasks[1];
        REQUIRE(desc == "First");
    }
}

TEST_CASE("Testing readTasksFromFile function")
{

    std::unordered_map<int, std::tuple<std::string, int, bool>> tasks;
    std::priority_queue<std::tuple<int, int, std::string>> pq;
    std::string filename = "test_temp.txt";

    SECTION("File opens successfully")
    {
        createTestFile(filename, "1 Test 5 false\n");

        bool result = readTasksFromFile(filename, tasks, pq);

        REQUIRE(result == true);

        std::remove(filename.c_str());
    }

    SECTION("File does not exist")
    {
        bool result = readTasksFromFile("nonexistent.txt", tasks, pq);

        REQUIRE(result == false);
        REQUIRE(tasks.empty());
    }

    SECTION("Reads tasks correctly")
    {
        std::string content = "1 Buy_milk 5 false\n"
                              "2 Do_homework 10 true\n";

        createTestFile(filename, content);

        readTasksFromFile(filename, tasks, pq);

        REQUIRE(tasks.size() == 2);
        REQUIRE(tasks.find(1) != tasks.end());
        REQUIRE(tasks.find(2) != tasks.end());

        std::remove(filename.c_str());
    }

    SECTION("Adds tasks to priority queue")
    {
        std::string content = "1 Buy_milk 5 false\n";
        createTestFile(filename, content);

        readTasksFromFile(filename, tasks, pq);

        REQUIRE_FALSE(pq.empty());
        auto [prio, id, desc] = pq.top();
        REQUIRE(prio == 5);
        REQUIRE(id == 1);

        std::remove(filename.c_str());
    }
}