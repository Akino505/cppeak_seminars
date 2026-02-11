#include "inputSample.hpp"

std::vector<double> inputSample(int rows, int columns)
{   
    double value = 0;
    std::vector<double> storage(rows * columns);
    for(int idx = 0; idx < rows * columns; ++idx)
    {
        std::cin >> value;
        storage[idx] = value;
    }
    return storage;
}