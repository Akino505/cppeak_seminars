#include "../include/storageEmployees.hpp"
#include <cstddef>
#include <stdexcept>

SafeVector::SafeVector(): data(nullptr), size(0) {}
SafeVector::~SafeVector() { delete[] data; }

const Employee& SafeVector::at(size_t index) const
{
    if(index >= size)
    {
        throw std::out_of_range("SafeVector::at out of range");
    }
    return data[index];
}

Employee& SafeVector::at(size_t index) {
    if (index >= size) {
        throw std::out_of_range("SafeVector::at out of range");
    }
    return data[index];
}

void SafeVector::push_back(const Employee& value)
{
    auto newData = new Employee[size + 1];
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

