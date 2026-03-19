#include "findDept.hpp"
#include "findName.hpp"
#include "findSalary.hpp"
#include "sortEmployees.hpp"
#include <catch2/catch_test_macros.hpp>
#include <cstring>

SafeVector createTestEmployees() {
    SafeVector employees;
    
    Employee e1;
    e1.setName("Alice");
    e1.setDept(1);
    e1.setSalary(5000);
    employees.push_back(e1);
    
    Employee e2;
    e2.setName("Bob");
    e2.setDept(2);
    e2.setSalary(6000);
    employees.push_back(e2);
    
    Employee e3;
    strcpy(e3.name, "Charlie");
    e3.dept = 1;
    e3.salary = 5500;
    employees.push_back(e3);
    
    Employee e4;
    strcpy(e4.name, "David");
    e4.dept = 2;
    e4.salary = 6000;
    employees.push_back(e4);
    
    return employees;
}

TEST_CASE("Testing findDept function")
{
    auto employees = createTestEmployees();
    
    SECTION("Find existing department")
    {
        auto result = findDept(employees, 1);
        
        REQUIRE(result.size() == 2);
        REQUIRE(strcmp(employees.at(result[0]).name, "Alice") == 0);
        REQUIRE(strcmp(employees.at(result[1]).name, "Charlie") == 0);
    }
    
    SECTION("Find non-existing department")
    {
        auto result = findDept(employees, 99);
        REQUIRE(result.empty());
    }
}

TEST_CASE("Testing findName function")
{
    auto employees = createTestEmployees();
    
    SECTION("Find existing name")
    {
        auto result = findName(employees, "Bob");
        
        REQUIRE(result.size() == 1);
        REQUIRE(result[0] == 1);
        REQUIRE(employees.at(result[0]).dept == 2);
        REQUIRE(employees.at(result[0]).salary == 6000);
    }
    
    SECTION("Find non-existing name")
    {
        auto result = findName(employees, "John");
        REQUIRE(result.empty());
    }
}

TEST_CASE("Testing findSalary function")
{
    auto employees = createTestEmployees();
    
    SECTION("Find existing salary")
    {
        auto result = findSalary(employees, 6000);
        
        REQUIRE(result.size() == 2);
        bool foundBob = false, foundDavid = false;
        for (int idx : result) {
            if (strcmp(employees.at(idx).name, "Bob") == 0) foundBob = true;
            if (strcmp(employees.at(idx).name, "David") == 0) foundDavid = true;
        }
        REQUIRE(foundBob);
        REQUIRE(foundDavid);
    }
    
    SECTION("Find non-existing salary")
    {
        auto result = findSalary(employees, 9999);
        REQUIRE(result.empty());
    }
}

TEST_CASE("Testing sortEmployees function")
{
    auto employees = createTestEmployees();
    
    SECTION("Sort by dept, then salary descending, then name")
    {
        sortEmployees(employees);
        
        REQUIRE(employees.size() == 4);
        
        REQUIRE(employees.at(0).dept == 1);
        REQUIRE(employees.at(0).salary == 5500);
        REQUIRE(strcmp(employees.at(0).name, "Charlie") == 0);
        
        REQUIRE(employees.at(1).dept == 1);
        REQUIRE(employees.at(1).salary == 5000);
        REQUIRE(strcmp(employees.at(1).name, "Alice") == 0);
        
        REQUIRE(employees.at(2).dept == 2);
        REQUIRE(employees.at(2).salary == 6000);
        REQUIRE(strcmp(employees.at(2).name, "Bob") == 0);
        
        REQUIRE(employees.at(3).dept == 2);
        REQUIRE(employees.at(3).salary == 6000);
        REQUIRE(strcmp(employees.at(3).name, "David") == 0);
    }
    
    SECTION("Sort empty vector")
    {
        SafeVector<Employee> empty;
        sortEmployees(empty);  
        REQUIRE(empty.empty());
    }
}