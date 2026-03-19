#include "../include/storageEmployees.hpp"

SafeVector::SafeVector(): data(nullptr), size(0) {}
SafeVector::~SafeVector() { delete[] data; }

Employee& SafeVector::at(int index)
{
    if(index < 0 || index >= size)
    {
        std::cout << "Ошибка: индекс вне диапазона!" << std::endl;
        exit(1);
    }
    return data[index];
}
