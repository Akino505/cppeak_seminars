# Task 5  
This is a small program - a task management system. The user provides a file "ToDoList.txt" with tasks in the format "id task priority status".  
- ID - the task number in the system. If a task with this number already exists, the system notifies the user, ignores the task, and continues working.
- TASK - the task description.
- PRIORITY - the task priority (from 0 to 10). The task with the highest priority is executed first.
- STATUS - the task status `true`/`false`, where true means completed, and false means not completed.  

Communication with the user is done via the console.
- help - Displays all commands.
- 1 - Execute the task with the highest priority
- 2 - Undo the execution of the last task
- 3 - Show uncompleted tasks
- exit - Terminate the program  

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
./build/project_5
```
# Unit tests  
```bash
./build/tests
```
