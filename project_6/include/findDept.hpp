#ifndef FIND_DEPT_HPP
#define FIND_DEPT_HPP

#include "employee.hpp"
#include <cstring>
#include <iostream>
#include <vector>

std::vector<int> findDept(const SafeVector<Employee>& employees, int dept);

#endif