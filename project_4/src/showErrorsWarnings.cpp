#include "showErrorsWarnings.hpp"
#include <array>

void showErrorsWarnings(std::fstream& inputFile)
{
    std::string line, date, time, level, message;
    std::map<std::string, int> errors; 
    std::map<std::string, int> warnings;
    
    while(getline(inputFile, line))
    {
        std::stringstream ss(line);

        ss >> date;
        if(!date.empty() && date[0] == '[')
        {
            date = date.substr(1);
        }

        ss >> time;
        if(!time.empty() && time.back() == ']')
        {
            time.pop_back();
        }

        ss >> level;
        getline(ss, message);
        
        if(!message.empty() && message[0] == ' ')
        {
            message = message.substr(1); 
        }
        
        if(level == "ERROR")
        {
            errors[message]++;
        }
        else if(level == "WARNING")
        {
            warnings[message]++;
        }
    }
    
    std::ofstream outFile("outFile.txt");

    outFile << "Result of command 4:" << std::endl;

    outFile << "ERRORS:" << std::endl;
    if(errors.empty())
    {
        outFile << "  No errors found" << std::endl;
    }
    else
    {
        for(const auto& e : errors)
        {
            outFile << "  \"" << e.first << "\" - " << e.second << " times" << std::endl;
        }
    }

    outFile << "WARNINGS:" << std::endl;
    if(warnings.empty())
    {
        outFile << "  No warnings found" << std::endl;
    }
    else
    {
        for(auto& w : warnings)
        {
            outFile << "  \"" << w.first << "\" - " << w.second << " times" << std::endl;
        }
    }

    outFile.close();
}
