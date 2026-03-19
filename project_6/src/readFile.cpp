#include "readFile.hpp"
#include "employee.hpp"
#include "storageEmployees.hpp"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>


SafeVector readBDFromFile(std::string filename)
{
    SafeVector employees;
    std::ifstream file(filename);
    if(!file.is_open())
    {
        std::cerr << "Error: Failed to open file " << filename << std::endl;
        return employees;
    }
    std::string line;

    while(std::getline(file, line))
    {
        if (line.empty()) continue;
        size_t name = line.find(';');
        size_t dept = line.find(';', name + 1);
        size_t salary = line.find(';', dept + 1);

        std::string sName = line.substr(0, name);
        std::string sDept = line.substr(name + 1, dept - name - 1);
        std::string sSalary = line.substr(dept + 1);

        try{
            int iDept = 0;
            double dSalary = -1.0;
            if (!(sDept.empty()))
            {
                iDept = std::stoi(sDept);
            }
            if (!(sSalary.empty())){
                dSalary = std::stod(sSalary);
            }
            employees.push_back({sName, iDept, dSalary});
        }catch(...)
        {
            std::cerr << "Number conversion error in line: " << line;
        }
    }
    return employees;
}