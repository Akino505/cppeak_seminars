#include "employee.hpp"
#include <string>

Employee::Employee(std::string name, int dept, double salary){
    setName(name);
    setDept(dept);
    setSalary(salary);
}

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
std::string Employee::getName() const { return name; }
int Employee::getDept() const { return dept; }
double Employee::getSalary() const { return salary; }
