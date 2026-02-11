#include "inputSample.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

std::vector<double> inputSample(int rows, int columns)
{   
    double value = 0;
    std::vector<double> storage;
    std::string row;
    while (rows){
        std::getline(std::cin, row);
        std::stringstream streamRow(row);
        while(streamRow >> value)
        {
            storage.push_back(value);
        }
        rows--;
    }
    return storage;
}