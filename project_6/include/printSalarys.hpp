#ifndef PRINT_SALARYS_HPP
#define PRINT_SALARYS_HPP

#include "findSalary.hpp"
#include "storageEmployees.hpp"
#include <fstream>
#include <vector>

void printSalarys(std::string filename, const SafeVector& employees,
                double salary);

#endif