#ifndef FIND_SALARY_HPP
#define FIND_SALARY_HPP

#include "employee.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>
#include <vector>
#include "storageEmployees.hpp"

std::vector<size_t> findSalary(const SafeVector& employees,
                            double salary);

#endif