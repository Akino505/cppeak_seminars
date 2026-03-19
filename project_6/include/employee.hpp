#include <string>

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

class Employee
{
private:
    std::string name = "Undefined";
    int dept = 0;
    double salary = -1;

public:
    Employee(std::string name, int dept, double salary);
    void setName(std::string sName);
    void setDept(int sDept);
    void setSalary(double sSalary);
    std::string getName() const;
    int getDept() const;
    double getSalary() const;
};

#endif