#include "employee.hpp"
#include "storageEmployees.hpp"
#include <vector>
#include <string>
#include <fstream>

#ifndef PRINT_FILE_HPP
#define PRINT_FILE_HPP

void printBD(std::string filename, const SafeVector& employees);

#endif