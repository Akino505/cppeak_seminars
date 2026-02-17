#include <iostream>
#include "readFile.hpp"
#include "countLvls.hpp"
#include "showErrorsWarnings.hpp"
#include "lvlsInRange.hpp"

std::ostream& operator<<(std::ostream& os, const std::array<std::string, 4>& arr)
{
    os << arr[0] << " " << arr[1] << " " << arr[2] << arr[3] << "\n";
    return os;
}

int main()
{
    std::ifstream fileIn("log_input.txt");
    std::ofstream fileOut("log_output.txt");
    std::vector<std::array<std::string, 4>> logBase = readFile(fileIn);
    std::string command = "";
    std::cout << "What do you want to do with the log file?" << "\n";
    std::cout << "1. Request the output of the types of levels and their counts" << "\n";
    std::cout << "2. Request the output of a specific level" << "\n";
    std::cout << "3. Request the output of levels within a specific time range" << "\n";
    std::cout << "4. Request the output of the most frequent messages for errors and warnings" << "\n";
    std::cout << "5. Request statistics for a specific time period" << "\n";
    std::cout << "Type 'help' for list of commands." << "\n";
    std::cout << "Type 'exit' to exit." << "\n";
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
            std::cout << "1. Request the output of the types of levels and their counts" << "\n";
            std::cout << "2. Request the output of a specific level" << "\n";
            std::cout << "3. Request the output of levels within a specific time range" << "\n";
            std::cout << "4. Request the output of the most frequent messages for errors and warnings" << "\n";
            std::cout << "5. Request statistics for a specific time period" << "\n";
        }
        else
        {
            std::cout << "Please, type appropriate command.";
            std::cout << "Type 'help' for list of commands." << "\n";
        }
    }
    std::cout << "Goodbye! :)" << "\n";
}