#include <iostream>
#include "readFile.hpp"
#include "countLvls.hpp"
#include "lvlsInRange.hpp"
#include "checkFile.hpp"
#include "specificLevel.hpp"
#include "help.hpp"
#include "showErrorsWarnings.hpp"
#include "statisticForPeriod.hpp"

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
            fileOut << "Result of command 1." << std::endl;
            fileOut << "Log files was written:" << std::endl;
            fileOut << "from: " << logBase[0][1] << " " << logBase[0][2] << std::endl;
            fileOut << "to: " << logBase[logBase.size() - 1][1] << " " << logBase[logBase.size() - 1][2] << std::endl;
            countLvls(logBase, fileOut);
            std::cout << "Proccess is done!" << "\n";
            std::cout << "Anything else?" << "\n";
            fileOut << "----------------------------------------------------------------------" << std::endl;
        }
        else if(command == "2")
        {
            if(!specificLevel(logBase, fileOut))
            {
                fileOut << "Result of command 2." << std::endl;
                fileOut << "ERROR: End with error." << std::endl;
                break;
            }
            std::cout << "Proccess is done!" << "\n";
            std::cout << "Anything else?" << "\n";
            fileOut << "----------------------------------------------------------------------" << std::endl;
        }
        else if(command == "3")
        {
            if(!lvlsInRange(logBase, fileOut))
            {
                fileOut << "Result of command 3." << std::endl;
                fileOut << "ERROR: End with error." << std::endl;
                break;
            }
            std::cout << "Proccess is done!" << "\n";
            std::cout << "Anything else?" << "\n";
            fileOut << "----------------------------------------------------------------------" << std::endl;
        }
        else if(command == "4")
        {
            if(!lvlsInRange2(logBase, fileOut))
            {
                fileOut << "Result of command 4." << std::endl;
                fileOut << "ERROR: End with error." << std::endl;
                break;
            }
            std::cout << "Proccess is done!" << "\n";
            std::cout << "Anything else?" << "\n";
            fileOut << "----------------------------------------------------------------------" << std::endl;
        }
        else if(command == "5")
        {
            if(!showErrorsWarnings(fileIn, fileOut))
            {
                fileOut << "Result of command 5." << std::endl;
                fileOut << "ERROR: End with error." << std::endl;
                break;
            }
            std::cout << "Proccess is done!" << "\n";
            std::cout << "Anything else?" << "\n";
            fileOut << "----------------------------------------------------------------------" << std::endl;
        }
        else if(command == "help")
        {
            help();
        }
        else if (command == "exit")
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