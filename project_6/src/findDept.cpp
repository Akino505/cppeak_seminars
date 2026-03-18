#include "findDept.hpp"

std::vector<int> findDept(const SafeVector<Employee>& employees, int dept)
{
    std::vector<int> idxs;
    for (size_t idx = 0; idx < employees.size(); idx++)
    {
        if (employees.at(idx).dept == dept)
        {
            idxs.push_back(idx);
        }
    }
    return idxs;
}