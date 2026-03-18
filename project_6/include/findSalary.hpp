#ifndef FIND_SALARY_HPP
#define FIND_SALARY_HPP

#include "employee.hpp"
#include <cstring>
#include <iostream>
#include <vector>

std::vector<int> findSalary(const SafeVector<Employee>& employees,
                            double salary);

#endif