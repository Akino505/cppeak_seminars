#include <iostream>
#include "readFile.hpp"
#include "countLvls.hpp"
#include "showErrorsWarnings.hpp"
#include "lvlsInRange.hpp"
#include "checkFile.hpp"
#include "help.hpp"

std::ostream& operator<<(std::ostream& os, const std::array<std::string, 4>& arr)
{
    os << arr[0] << " " << arr[1] << " " << arr[2] << arr[3] << "\n";
    return os;
}

int main()
{
    std::ifstream fileIn("log_input.txt");
    std::ofstream fileOut("log_output.txt");
    if(!checkFile(fileIn)) return 0;
    std::vector<std::array<std::string, 4>> logBase = readFile(fileIn);
    std::string command = "";
    std::cout << "What do you want to do with the log file?" << "\n";
    help();
    while(command != "exit")
    {
        std::cin >> command;
        if(command == "1")
        {   
            countLvls(logBase, fileOut);
            fileOut << "----------------------------------------------------------------------" << "\n";
        }
        else if(command == "3")
        {
            if(!lvlsInRange(logBase, fileOut)) fileOut << "ERROR: End with error.";
            fileOut << "----------------------------------------------------------------------" << "\n";
        }
        else if(command == "4")
        {   
            showErrorsWarnings(fileIn);
            fileOut << "----------------------------------------------------------------------" << "\n";
        }
        else if(command == "help")
        {
            help();
        }
        else
        {
            std::cout << "Please, type appropriate command.";
            std::cout << "Type 'help' for list of commands." << "\n";
        }
    }
    std::cout << "Goodbye! :)" << "\n";
}