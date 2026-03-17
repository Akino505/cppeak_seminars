#include "employee.hpp"
#include <vector>

#ifndef READ_FILE
#define READ_FILE

std::vector<Employee> readBDFromFile(const std::string& filename);

#endif