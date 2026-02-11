#include "median.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


std::pair<double, double> median(std::vector<double> matrix)
{
    std::sort(matrix.begin(), matrix.end());
    size_t lenVect = matrix.size();
    std::pair<double, double> medians = {NULL, NULL};
    if(lenVect % 2 == 0)
    {
        medians.first = matrix[lenVect / 2 - 1];
        medians.second = matrix[lenVect / 2];
    }
    else
    {
        medians.first = matrix[lenVect / 2];
        medians.second = matrix[lenVect / 2];

    }
    return medians;
}
