#include "sortEmployees.hpp"

bool compareEmployee(const Employee& first, const Employee& second)
{
    return std::tie(first.dept, std::greater<double>()(second.salary, first.salary), first.name) <
           std::tie(second.dept, std::greater<double>()(first.salary, second.salary), second.name);
}

void sortEmployees(SafeVector<Employee>& employees)
{
    std::sort(employees.begin(), employees.end(), compareEmployee);
}