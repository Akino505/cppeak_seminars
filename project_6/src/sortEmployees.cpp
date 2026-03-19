#include "sortEmployees.hpp"

bool compareEmployee(const Employee& first, const Employee& second)
{
    if (first.getDept() != second.getDept())
        return first.getDept() < second.getDept();
    if (first.getSalary() != second.getSalary())
        return first.getSalary() > second.getSalary();
    return first.getName() < second.getName();
}

void sortEmployees(SafeVector& employees)
{
    std::sort(employees.begin(), employees.end(), compareEmployee);
}