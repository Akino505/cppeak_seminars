#include "findSalary.hpp"

std::vector<int> findSalary(const SafeVector& employees, double salary)
{
    std::vector<int> idxs;
    for (size_t idx = 0; idx < employees.getSize(); idx++)
    {
        if (employees.at(idx).getSalary() == salary)
        {
            idxs.push_back(idx);
        }
    }
    return idxs;
}