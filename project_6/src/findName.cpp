#include "findName.hpp"

std::vector<int> findName(const SafeVector& employees, const char* name)
{
    std::vector<int> idxs;
    for (size_t idx = 0; idx < employees.getSize(); idx++)
    {
        if (employees.at(idx).getName() == name)
        {
            idxs.push_back(idx);  
        }
    }

    return idxs;  
}