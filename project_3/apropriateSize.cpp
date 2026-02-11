#include "apropriateSize.hpp"

bool apropriateSize(std::vector<double> matrix, int expect)
{
    bool flag = true;
    if(matrix.size() > expect)
    {
        std::cout << "ERROR: To many elements!" << "\n";
        flag = false;
    }
    else if (matrix.size() < expect)
    {
        std::cout << "ERROR: Not enough elements!" << "\n";
        flag = false;
    }
    if(!flag)
    {
        std::cout << "Expected: " << expect << "\n" << "Got: " << matrix.size() << "\n";
    }
    return flag;
}
