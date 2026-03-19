#include "employee.hpp"
#include "readFile.hpp"
#include "printFile.hpp"
#include "storageEmployees.hpp"
#include "sortEmployees.hpp"
#include "printDepts.hpp"
#include "printNames.hpp"
#include "printSalarys.hpp"

int main(){
    SafeVector employees = readBDFromFile("read.txt");
    printDepts("outd.txt", employees, 5);
    printSalarys("outs.txt", employees, 10000);
    printNames("outn.txt", employees, "Tom Black");
    sortEmployees(employees);
    printBD("out.txt", employees);
}