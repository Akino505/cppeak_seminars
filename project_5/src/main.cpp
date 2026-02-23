#include "addTask.hpp"
#include "getPendingTasks.hpp"
#include "help.hpp"
#include "readFile.hpp"
#include <fstream>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <iostream>

int main()
{
    std::ofstream fileOut("undoneTasks.txt");
    std::priority_queue<std::tuple<int, int, std::string>> doTasks;
    std::stack<std::tuple<int, std::string, int>> undoTasks;
    std::unordered_map<int, std::tuple<std::string, int, bool>> tasks;
    // readTasksFromFile("ToDoList.txt", tasks, doTasks, id?);
    std::string command = "";
    std::cout << "Let's work with your To-Do-List." << "\n";
    help();
    while(command != "exit")
    {
        std::cin >> command;
        if(command == "1")
        {
            // Complete the task
        }
        else if(command == "2")
        {
            // Cancel the task
        }
        else if(command == "3")
        {
            getPendingTasks(tasks, fileOut);
        }
        else if(command == "help")
        {
            help();
        }
        else if(command == "exit")
        {
            std::cout << "Goodbye! :)" << "\n";
            fileOut.close();
        }
        else
        {
            std::cout << "Please, type appropriate command." << "\n";
            std::cout << "Type 'help' for list of commands." << "\n";
        }
    }
}