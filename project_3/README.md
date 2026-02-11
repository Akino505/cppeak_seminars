# Task 3  
This project implemented a program that read matrix and calculate its mode, median and mean deviation.  
User puts `n` rows and `m` colums, than puts digits from matrix. Program warn if amount of digits less or more than `n * m`.  
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
./build/project_3
```
# Unit tests  
```bash
./build/tests
```
