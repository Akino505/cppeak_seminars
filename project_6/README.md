# Task 6  
This is a small program for working with an employee database. It implements:  
1. Sorting employees by department in ascending order and by salary in descending order  
2. Searching for employees with a given name  
3. Searching for employees with a given salary  
4. Searching for employees with a given department
  
The user provides a file "read.txt" with tasks in the format "name;department;salary".
- NAME – employee name. If the name cannot be recognized, returns UNDEFINED  
- DEPARTMENT – the department where the employee works. If an invalid department is specified, returns 0  
- SALARY – the salary received by the employee. If an invalid salary is specified, returns -1  
CMake was used for building, and Catch2 for unit tests.  

# Build
### Configuration (setup) of the project  
```bash
cmake -S . -B build
```
### Build the project
```bash
cmake --build build
```
# Run  
```bash
./build/project_6
```
# Unit tests  
```bash
./build/tests
```
