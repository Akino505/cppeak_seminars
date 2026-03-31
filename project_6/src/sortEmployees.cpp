#include "sortEmployees.hpp"
#include <tuple>

bool compareEmployee(const Employee& first, const Employee& second)
{
    int deptFirst = first.getDept();
    double salFirst = first.getSalary();
    std::string nameFirst = first.getName();
    int deptSecond = second.getDept();
    double salSecond = second.getSalary();
    std::string nameSecond = second.getName();
    bool cmpSalaryFirst =
        std::greater<double>()(second.getSalary(), first.getSalary());
    bool cmpSalarySecond =
        std::greater<double>()(first.getSalary(), second.getSalary());
    return std::tie(deptFirst, cmpSalaryFirst, nameFirst) <
           std::tie(deptSecond, cmpSalarySecond, nameSecond);
}

void sortEmployees(SafeVector& employees)
{
    std::sort(employees.begin(), employees.end(), compareEmployee);
}