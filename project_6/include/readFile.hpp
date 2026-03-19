#include "employee.hpp"
#include "storageEmployees.hpp"
#include <vector>

#ifndef READ_FILE
#define READ_FILE

SafeVector readBDFromFile(std::string filename);

#endif