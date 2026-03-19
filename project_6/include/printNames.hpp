#ifndef PRINT_NAMES_HPP
#define PRINT_NAMES_HPP

#include "findName.hpp"
#include "storageEmployees.hpp"
#include <fstream>
#include <string>
#include <vector>

void printNames(std::string filename, const SafeVector& employees,
                std::string name);

#endif