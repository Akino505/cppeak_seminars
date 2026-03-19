#ifndef FIND_SALARY_HPP
#define FIND_SALARY_HPP

#include "employee.hpp"
#include <cstring>
#include <iostream>
#include <vector>
#include "storageEmployees.hpp"

std::vector<int> findSalary(const SafeVector& employees,
                            double salary);

#endif