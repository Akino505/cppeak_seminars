#include "inputSample.hpp"

std::vector<double> inputSample(int rows, int columns)
{   
    double value = 0;
    std::vector<double> storage;
    std::string row;
    std::getline(std::cin, row);
    std::stringstream streamRow(row);
    while(streamRow >> value)
    {
        storage.push_back(value);
    }
    return storage;
}