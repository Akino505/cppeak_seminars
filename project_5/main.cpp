#include <fstream>
#include <string>
#include <queue>
#include <tuple>
#include <stack>
#include <unordered_map>
#include "help.hpp"

int main()
{
    std::ifstream fileIn("log_input.txt");
    std::ofstream fileOut("log_output.txt");
    std::priority_queue<std::tuple<int, int, std::string>>;
    std::stack<std::tuple<int, std::string, int>>;
    std::unordered_map<int, std::tuple<std::string, int, bool>>;
    // Чтение файла
    std::string command = "";
    std::cout << "Let's work with your To-Do-List." << "\n";
    help();
    while(command != "exit")
    {
        std::cin >> command;
        if(command == "1")
        {
            //Complete the task
        }
        else if(command == "2")
        {
            //Cancel the task
        }
        else if(command == "3")
        {
            //getPendingTasks(const std::unordered_map<...>& tasks)
        }
        else if(command == "help")
        {
            help();
        }
        else if(command == "exit")
        {
            std::cout << "Goodbye! :)" << "\n";
            fileIn.close();
            fileOut.close();
        }
        else
        {
            std::cout << "Please, type appropriate command." << "\n";
            std::cout << "Type 'help' for list of commands." << "\n";
        }
    }
}