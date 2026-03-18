#include "findName.hpp"

std::vector<int> findName(const SafeVector<Employee>& employees, const char* name)
{
    std::vector<int> idxs;
    for (size_t idx = 0; idx < employees.size(); idx++)
    {
        if (strcmp(employees.at(idx).name, name) == 0)
        {
            idxs.push_back(idx);  
        }
    }

    return idxs;  
}