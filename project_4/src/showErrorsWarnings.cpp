#include "showErrorsWarnings.hpp"

bool showErrorsWarnings(std::ifstream& FileIn, std::ofstream& FileOut)
{
    if (!FileIn.is_open())
    {
        return false;
    }

    FileIn.clear();
    FileIn.seekg(0);

    std::string line, date, time, level, message;
    std::map<std::string, int> errors; 
    std::map<std::string, int> warnings;
    
    while (getline(FileIn, line))
    {
        std::stringstream ss(line);

        ss >> level;

        ss >> date;
        if (!date.empty() && date[0] == '[')
        {
            date = date.substr(1);
        }

        ss >> time;
        if (!time.empty() && time.back() == ']')
        {
            time.pop_back();
        }
        getline(ss, message);
        
        if (!message.empty() && message[0] == ' ')
        {
            message = message.substr(1); 
        }
        
        if (level == "ERROR")
        {
            errors[message]++;
        }
        else if (level == "WARNING") 
        {
            warnings[message]++;
        }
    }
    
    FileOut << "Result of command 5:" << std::endl;

    FileOut << "ERRORS:" << std::endl;
    if (errors.empty()) {
        FileOut << "  No errors found" << std::endl;
    } else {
        for (const auto& e : errors) {
            FileOut << "  \"" << e.first << "\" - " << e.second << " times" << std::endl;
        }
    }

    FileOut << "WARNINGS:" << std::endl;
    if (warnings.empty()) {
        FileOut << "  No warnings found" << std::endl;
    } else {
        for (auto& w : warnings) {
            FileOut << "  \"" << w.first << "\" - " << w.second << " times" << std::endl;
        }
    }
    return true;
}
