#include "findDept.hpp"
#include <cstddef>

std::vector<size_t> findDept(const SafeVector& employees, int dept)
{
    std::vector<size_t> idxs;
    for (size_t idx = 0; idx < employees.getSize(); idx++)
    {
        if (employees.at(idx).getDept() == dept)
        {
            idxs.push_back(idx);
        }
    }
    return idxs;
}