#include "printNames.hpp"

void printNames(const std::string& filename, const SafeVector& employees,
                const std::string& name)
{
    std::vector<size_t> names = findName(employees, name);
    std::ofstream outFile(filename);
    outFile << "Employees with name: " << name << std::endl;
    if(names.empty())
    {
        outFile << "No employees with name " << name << std::endl;
        outFile.close();
        return;
    }
    for(int idx: names)
    {
        outFile << "Name: " << employees.at(idx).getName()
                << " | Dept: " << employees.at(idx).getDept()
                << " | Salary: " << employees.at(idx).getSalary() << '\n';
    }
}
