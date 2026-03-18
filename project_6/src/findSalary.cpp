#include "findSalary.hpp"

std::vector<int> findSalary(const SafeVector<Employee>& employees, double salary)
{
    std::vector<int> idxs;
    for (size_t idx = 0; idx < employees.size(); idx++)
    {
        if (employees.at(idx).salary == salary)
        {
            idxs.push_back(idx);
        }
    }
    return idxs;
}