#include "mode.h"

double temp;

auto is_equal = [](auto a)
{
    return a == temp;
};

double mode(const std::vector<double> &matrix)
{
    double modeAns = 0;
    int modeNum = 0;
    double eps = 1e-9;

    for(int i = 0; i < matrix.size(); i++)
    {
        temp = matrix[i];
        int num = std::count_if(matrix.begin(), matrix.end(), is_equal);

        if (num > modeNum)
        {
            modeNum = num;
            modeAns = matrix[i];
        }
    }
    return modeAns;
}
