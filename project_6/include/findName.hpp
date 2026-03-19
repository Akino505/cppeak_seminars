#ifndef FIND_NAME_HPP
#define FIND_NAME_HPP

#include "employee.hpp"
#include <cstring>
#include <iostream>
#include "storageEmployees.hpp"
#include <vector>

std::vector<int> findName(const SafeVector& employees,
                          const char* name);

#endif
