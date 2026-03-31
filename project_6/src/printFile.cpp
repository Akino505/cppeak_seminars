#include "printFile.hpp"
#include "employee.hpp"
#include "storageEmployees.hpp"

void printBD(const std::string& filename, const SafeVector& employees)
{
    std::ofstream outFile(filename);
    outFile << "EMPLOYEES" << "\n";
    for(const Employee& employee: employees)
    {
        outFile << "Name: " << employee.getName()
                << " | Dept: " << employee.getDept()
                << " | Salary: " << employee.getSalary() << '\n';
    }
    outFile.close();
}
