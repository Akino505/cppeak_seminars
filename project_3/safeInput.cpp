#include <cmath>
#include <iostream>
#include <safeInput.hpp>

bool isInt(double val)
{
    return val == std::trunc(val);
}

int safeInput(double value)
{
    int flag = 1;
    if(!isInt(value))
    {
        std::cout << "ERROR: Size must be integer";
        flag = 0;
    }
    if(value <= 0)
    {
        std::cout << "ERROR: Size must be positive.";
        flag = 0;
    }
    return flag;
}