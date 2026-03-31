#ifndef FIND_NAME_HPP
#define FIND_NAME_HPP

#include "employee.hpp"
#include "storageEmployees.hpp"
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

std::vector<size_t> findName(const SafeVector& employees,
                             const std::string& name);

#endif
