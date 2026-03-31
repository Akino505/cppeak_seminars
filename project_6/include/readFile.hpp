#include "employee.hpp"
#include "storageEmployees.hpp"
#include <vector>

#ifndef READ_FILE
#define READ_FILE

SafeVector readBDFromFile(const std::string& filename);

#endif