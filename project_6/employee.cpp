#include "employee.hpp"
#include <string>

void Employee::setName(std::string sName)
{
    if(!sName.empty())
        name = sName;
}
void Employee::setDept(int sDept)
{
    if(sDept > 0)
        dept = sDept;
}
void Employee::setSalary(double sSalary)
{
    if(sSalary >= 0)
        salary = sSalary;
}
std::string Employee::getName() { return name; }
int Employee::getDept() { return dept; }
double Employee::getSalary() { return salary; }
