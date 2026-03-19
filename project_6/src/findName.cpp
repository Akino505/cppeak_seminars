#include "findName.hpp"

std::vector<size_t> findName(const SafeVector& employees, std::string name)
{
    std::vector<size_t> idxs;
    for (size_t idx = 0; idx < employees.getSize(); idx++)
    {
        if (employees.at(idx).getName() == name)
        {
            idxs.push_back(idx);  
        }
    }

    return idxs;  
}