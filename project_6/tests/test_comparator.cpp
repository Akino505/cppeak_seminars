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
    e3.setName("Charlie");
    e3.setDept(1);
    e3.setSalary(5500);
    employees.push_back(e3);
    
    Employee e4;
    e4.setName("David");
    e4.setDept(2);
    e4.setSalary(6000);
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
        REQUIRE(employees.at(result[0]).getName() =="Alice");
        REQUIRE(employees.at(result[1]).getName() == "Charlie");
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
        REQUIRE(employees.at(result[0]).getDept() == 2);
        REQUIRE(employees.at(result[0]).getSalary() == 6000);
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
            if (employees.at(idx).getName() == "Bob") foundBob = true;
            if (employees.at(idx).getName() == "David") foundDavid = true;
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
        
        REQUIRE(employees.getSize() == 4);
        
        REQUIRE(employees.at(0).getDept() == 1);
        REQUIRE(employees.at(0).getSalary() == 5500);
        REQUIRE(employees.at(0).getName() == "Charlie");
        
        REQUIRE(employees.at(1).getDept() == 1);
        REQUIRE(employees.at(1).getSalary() == 5000);
        REQUIRE(employees.at(1).getName() == "Alice");
        
        REQUIRE(employees.at(2).getDept() == 2);
        REQUIRE(employees.at(2).getSalary() == 6000);
        REQUIRE(employees.at(2).getName() == "Bob");
        
        REQUIRE(employees.at(3).getDept() == 2);
        REQUIRE(employees.at(3).getSalary() == 6000);
        REQUIRE(employees.at(3).getName() == "David");
    }
}