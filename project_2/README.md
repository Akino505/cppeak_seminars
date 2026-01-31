# Task 2 - Password Security Check  
This project implemented a program that checks a user-entered password for meeting following conditions:  
* The password contains only Latin letters and allowed special characters.
* The password length is at least 8 characters.
* The password contains at least one uppercase letter.
* The password contains at least one lowercase letter.
* The password contains at least one digit.
* The password contains at least one allowed special character.
  
Allowed special characters: (~!@#$%^&*()+`=-_[]{}<>.,:;/|\)  
If all conditions are satisfied, the program reports that the user's password is secure. Otherwise, it outputs to the user all conditions that were not met.  
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
./build/project_2
```
# Unit tests  
```bash
./build/tests
```
