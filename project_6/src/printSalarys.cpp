#include "printSalarys.hpp"
#include "findSalary.hpp"
#include <cstddef>

void printSalarys(const std::string& filename, const SafeVector& employees,
                  double salary)
{
    std::vector<size_t> salarys = findSalary(employees, salary);
    std::ofstream outFile(filename);
    outFile << "Employees with salary: " << salary << "\n";
    if(salarys.empty()){
        outFile << "No employees in dept " << salary << std::endl;    
        outFile.close();
        return;
    }
    for(int idx: salarys)
    {
        outFile << "Name: " << employees.at(idx).getName()
                << " | Dept: " << employees.at(idx).getDept()
                << " | Salary: " << employees.at(idx).getSalary() << '\n';
    }
}
