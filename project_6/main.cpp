#include "employee.hpp"
#include "readFile.hpp"
#include "printFile.hpp"
#include <vector>

int main(){
    std::vector<Employee> employees = readBDFromFile("read.txt");
    printBD("out.txt", employees);
}