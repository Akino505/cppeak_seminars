#include <fstream>
#include <string>
#include <vector>
#include "employee.hpp"
#include "printFile.hpp"

void printBD(std::string filename, const std::vector<Employee>& employees){ //change to SafeVector
    std::ofstream outFile(filename);
    for (Employee employee : employees)
    {
        outFile << "Name: " << employee.getName() << " | Dept: " << employee.getDept() << " | Salary: " << employee.getSalary() << '\n'; 
    }
}
