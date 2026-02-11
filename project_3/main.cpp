#include "mode.hpp"
#include "meanDeviation.hpp"
#include "median.hpp"
#include "inputSample.hpp"
#include "safeInput.hpp"
#include "apropriateSize.hpp"

int main()
{
    int rows = 0;
    int columns = 0;
    std::cout << "Input rows and columns:" << "\n";
    std::cin >> rows >> columns;
    if(!safeInput(rows) || !safeInput(columns)) return 0;
    int expected = rows * columns;
    std::cout << "Input " << rows << " rows and " << columns << " columns:" << "\n";
    std::vector<double> matrix = inputSample(rows, columns);
    if(!apropriateSize(matrix, rows * columns)) return 0;
    double meanDev = meanDeviation(matrix, rows, columns);
    double modeVal = mode(matrix);
    std::pair medianVals = median(matrix);
    std::cout << "Result of mean deviation: " << meanDev << "\n";
    std::cout << "Result of mode: " << modeVal << "\n";
    std::cout << "Result of median: ";
    if(matrix.size() % 2 == 0)
    {
        std::cout << medianVals.first << " " << medianVals.second << "\n";
    }
    else
    {
        std::cout << medianVals.first << "\n";
    }
}
