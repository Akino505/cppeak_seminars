#ifndef STORAGE_EMPLOYEE_HPP
#define STORAGE_EMPLOYEE_HPP

#include "../include/employee.hpp"
#include <iostream>

class SafeVector
{
private:
    Employee* data;
    size_t size;

public:
    SafeVector();
    ~SafeVector();

    const Employee& at(size_t index) const;
    void push_back(const Employee& value);
    Employee* begin() const;
    Employee* end() const;
    size_t getSize() const;
};

#endif