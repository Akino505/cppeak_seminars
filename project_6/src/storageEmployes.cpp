#include "../include/storageEmployees.hpp"
#include <cstddef>

SafeVector::SafeVector(): data(nullptr), size(0) {}
SafeVector::~SafeVector() { delete[] data; }

const Employee& SafeVector::at(size_t index) const
{
    if(index < 0 || index >= size)
    {
        std::cout << "Ошибка: индекс вне диапазона!" << std::endl;
        exit(1);
    }
    return data[index];
}

void SafeVector::push_back(const Employee& value)
{
    Employee* newData = new Employee[size + 1];
    for (size_t idx = 0; idx < size; ++idx){
        newData[idx] = data[idx];
    }
    newData[size] = value;
    delete[] data;
    data = newData;
    ++size;
}

Employee* SafeVector::begin() const { return data; }
Employee* SafeVector::end() const { return data + size; }
size_t SafeVector::getSize() const { return size; }

