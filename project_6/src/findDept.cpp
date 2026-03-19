#include "findDept.hpp"

std::vector<int> findDept(const SafeVector& employees, int dept)
{
    std::vector<int> idxs;
    for (size_t idx = 0; idx < employees.getSize(); idx++)
    {
        if (employees.at(idx).getDept() == dept)
        {
            idxs.push_back(idx);
        }
    }
    return idxs;
}