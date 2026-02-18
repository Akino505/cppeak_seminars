#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <vector>
#include <array>

#ifndef STAT_FOR_PERIOD_HPP
#define STAT_FOR_PERIOD_HPP

void countLvlsSecond(std::vector<std::array<std::string, 4>> logBase, std::ofstream& out);

bool lvlsInRange2(std::vector<std::array<std::string, 4>> logBase, std::ofstream& out);

#endif