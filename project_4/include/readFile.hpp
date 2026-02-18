#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <array>

#ifndef READ_FILE_HPP
#define READ_FILE_HPP

std::vector<std::array<std::string, 4>> readFile(std::ifstream& file);

#endif