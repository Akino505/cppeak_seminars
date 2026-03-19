#ifndef FIND_DEPT_HPP
#define FIND_DEPT_HPP

#include "employee.hpp"
#include "storageEmployees.hpp"
#include <cstring>
#include <iostream>
#include <vector>

std::vector<size_t> findDept(const SafeVector& employees, int dept);

#endif