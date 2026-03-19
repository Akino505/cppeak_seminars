#ifndef STORAGE_EMPLOYEE_HPP
#define STORAGE_EMPLOYEE_HPP

#include "../include/employee.hpp"
#include <iostream>

class SafeVector
{
private:
    Employee* data;
    int size;

public:
    SafeVector();
    ~SafeVector();

    Employee& at(int index);
    const Employee& at(size_t index) const;
};

#endif