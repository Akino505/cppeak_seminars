#include "findSalary.hpp"
#include <cstddef>

std::vector<size_t> findSalary(const SafeVector& employees, double salary)
{
    std::vector<size_t> idxs;
    for (size_t idx = 0; idx < employees.getSize(); idx++)
    {
        if (employees.at(idx).getSalary() == salary)
        {
            idxs.push_back(idx);
        }
    }
    return idxs;
}