#include "safeInput.hpp"
#include <cmath>
#include <iostream>

bool isInt(double val)
{
    return val == std::trunc(val);
}

bool safeInput(double value)
{
    bool flag = true;
    if(!isInt(value))
    {
        std::cout << "ERROR: Size must be integer" << "\n";
        flag = false;
    }
    if(value <= 0)
    {
        std::cout << "ERROR: Size must be positive." << "\n";
        flag = false;
    }
    return flag;
}