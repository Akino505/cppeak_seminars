#ifndef PRINT_NAMES_HPP
#define PRINT_NAMES_HPP

#include "findName.hpp"
#include "storageEmployees.hpp"
#include <fstream>
#include <string>
#include <vector>

void printNames(const std::string& filename, const SafeVector& employees,
                const std::string& name);

#endif