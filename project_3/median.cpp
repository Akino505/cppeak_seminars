#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

std::vector<double> inputSample()
{
    std::vector<double> matrix;
    return matrix;
}

std::pair<double, double> median(std::vector<double> matrix)
{
    std::sort(matrix.begin(), matrix.end());
    size_t len_vect = matrix.size();
    std::pair<double, double> medians = {NULL, NULL};

    if (len_vect % 2 == 0)
    {
        medians.first = matrix[len_vect / 2 - 1];
        medians.second = matrix[len_vect / 2];
    }
    else
    {
        medians.first = matrix[len_vect / 2];
    }
    return medians;
}

int main()
{
    std::vector<double> matrix = {1.2, 3.4, 2.3424532454, 4.4444, 1};
    std::pair<double, double> mediana = median(matrix);
    std::cout << mediana.first << " " << mediana.second;
}