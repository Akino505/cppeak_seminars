#include "employee.hpp"
#include "readFile.hpp"
#include "storageEmployees.hpp"
#include <catch2/catch_test_macros.hpp>
#include <cstdio>
#include <fstream>
#include <string>

struct TempFile
{
    std::string path;

    TempFile(const std::string& content)
    {
        path = "test_" + std::to_string(rand()) + ".txt";
        std::ofstream f(path);
        f << content;
    }

    ~TempFile() { std::remove(path.c_str()); }
};

TEST_CASE("Read valid file with multiple employees", "[readFile]")
{
    std::string content = "John;10;50000.5\nJane;20;60000\n";
    TempFile file(content);

    SafeVector employees = readBDFromFile(file.path);

    REQUIRE(employees.getSize() == 2);
    CHECK(employees.at(0).getName() == "John");
    CHECK(employees.at(0).getDept() == 10);
    CHECK(employees.at(0).getSalary() == 50000.5);
    CHECK(employees.at(1).getName() == "Jane");
    CHECK(employees.at(1).getDept() == 20);
    CHECK(employees.at(1).getSalary() == 60000);
}

TEST_CASE("Skip empty lines", "[readFile]")
{
    std::string content = "John;10;50000.5\n\nJane;20;60000\n";
    TempFile file(content);

    SafeVector employees = readBDFromFile(file.path);

    REQUIRE(employees.getSize() == 2);
    CHECK(employees.at(0).getName() == "John");
    CHECK(employees.at(1).getName() == "Jane");
}


TEST_CASE("Department zero", "[readFile]")
{
    std::string content = "John;0;50000\n";
    TempFile file(content);

    SafeVector employees = readBDFromFile(file.path);

    REQUIRE(employees.getSize() == 1);
    CHECK(employees.at(0).getName() == "John");
    CHECK(employees.at(0).getDept() == 0);
    CHECK(employees.at(0).getSalary() == 50000);
}

TEST_CASE("Negative department",
          "[readFile]")
{
    std::string content = "John;-5;50000\n";
    TempFile file(content);

    SafeVector employees = readBDFromFile(file.path);

    REQUIRE(employees.getSize() == 1);
    CHECK(employees.at(0).getName() == "John");
    CHECK(employees.at(0).getDept() == 0);
    CHECK(employees.at(0).getSalary() == 50000);
}

TEST_CASE("Negative salary", "[readFile]")
{
    std::string content = "John;10;-100.5\n";
    TempFile file(content);

    SafeVector employees = readBDFromFile(file.path);

    REQUIRE(employees.getSize() == 1);
    CHECK(employees.at(0).getName() == "John");
    CHECK(employees.at(0).getDept() == 10);
    CHECK(employees.at(0).getSalary() == -1);
}

TEST_CASE("Salary zero is accepted", "[readFile]")
{
    std::string content = "John;10;0\n";
    TempFile file(content);

    SafeVector employees = readBDFromFile(file.path);

    REQUIRE(employees.getSize() == 1);
    CHECK(employees.at(0).getName() == "John");
    CHECK(employees.at(0).getDept() == 10);
    CHECK(employees.at(0).getSalary() == 0.0);
}

TEST_CASE(
    "Empty department field",
    "[readFile]")
{
    std::string content = "John;;50000\n";
    TempFile file(content);
    SafeVector employees = readBDFromFile(file.path);
    REQUIRE(employees.getSize() == 1);
    CHECK(employees.at(0).getName() == "John");
    CHECK(employees.at(0).getDept() == 0);
    CHECK(employees.at(0).getSalary() == 50000);
}

TEST_CASE("Empty salary field",
          "[readFile]")
{
    std::string content = "John;10;\n";
    TempFile file(content);

    SafeVector employees = readBDFromFile(file.path);
    REQUIRE(employees.getSize() == 1);
    CHECK(employees.at(0).getName() == "John");
    CHECK(employees.at(0).getDept() == 10);
    CHECK(employees.at(0).getSalary() == -1.0);
}
