# Task 4  
This is a small program that reads and analyzes a log file. Its main function is to output the types of levels and their counts to another file, as well as the start and end timestamps of the log file.

Additional features have also been implemented:
- The user can request the output of a specific level.
- The user can request the output of levels within a specific time range.
- The user can request the output of the most frequent messages for errors and warnings.
- The user can request statistics for a specific time period.

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
./build/project_4
```
# Unit tests  
```bash
./build/tests
```
