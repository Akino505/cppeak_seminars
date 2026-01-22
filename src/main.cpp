#include <iostream>
#include "mult.h"

int main()
{
    long long firstNumber = 0;
    long long secondNumber = 0;

    std::cout << "Input 2 integers" << std::endl;
    std::cin >> firstNumber >> secondNumber;

    std::cout << "Multiplication is: " << multiply(firstNumber, secondNumber) << std::endl;

    return 0;
}