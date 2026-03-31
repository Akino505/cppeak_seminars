#ifndef PRINT_DEPT_HPP
#define PRINT_DEPT_HPP

#include "findDept.hpp"
#include "storageEmployees.hpp"
#include <fstream>
#include <vector>

void printDepts(const std::string& filename, const SafeVector& employees, int dept);

#endif