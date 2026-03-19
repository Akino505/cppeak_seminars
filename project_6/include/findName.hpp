#ifndef FIND_NAME_HPP
#define FIND_NAME_HPP

#include "employee.hpp"
#include <cstring>
#include <iostream>
#include "storageEmployees.hpp"
#include <string>
#include <vector>

std::vector<size_t> findName(const SafeVector& employees,
                          std::string name);

#endif
