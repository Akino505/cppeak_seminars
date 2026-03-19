#include "printDepts.hpp"
#include "findDept.hpp"

void printDepts(std::string filename, const SafeVector& employees, int dept)
{
    std::ofstream outFile(filename);
    std::vector<size_t> depts = findDept(employees, dept);
    outFile << "Employees in dept: " << dept << "\n";
    if(depts.empty()){
        outFile << "No employees in dept " << dept << std::endl;    
        outFile.close();
        return;
    }
    for(int idx: depts)
    {
        outFile << "Name: " << employees.at(idx).getName()
                << " | Dept: " << employees.at(idx).getDept()
                << " | Salary: " << employees.at(idx).getSalary() << '\n';
    }
    outFile.close();
}
