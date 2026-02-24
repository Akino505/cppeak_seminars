#include "readFile.hpp"
#include "addTask.hpp"

bool readTasksFromFile(const std::string& filename, 
                       std::unordered_map<int, std::tuple<std::string, int, bool>>& tasks,
                       std::priority_queue<std::tuple<int, int, std::string>>& pq)
{
    
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Failed to open file " << filename << std::endl;
        return false;
    }
    
    std::string line;
    int lineNum = 0;
    int addedCount = 0;
    int errorCount = 0;
    
    while (std::getline(file, line))
    {
        lineNum++;
        if (line.empty())
        {
            continue;
        }
        
        std::istringstream iss(line);
        int id;
        int priority;
        std::string statusStr;
        
        if (!(iss >> id))
        {
            std::cerr << "  Error in line " << lineNum << std::endl;
            errorCount++;
            continue;
        }
        
        std::string rest;
        std::getline(iss, rest);
        
        size_t lastSpace = rest.find_last_of(" \t");
        if (lastSpace == std::string::npos)
        {
            std::cerr << "  Error in line " << lineNum << std::endl;
            errorCount++;
            continue;
        }
        
        size_t secondLastSpace = rest.find_last_of(" \t", lastSpace - 1);
        if (secondLastSpace == std::string::npos)
        {
            std::cerr << "  Error in line " << lineNum << std::endl;
            errorCount++;
            continue;
        }
        
        std::string priorityStr = rest.substr(secondLastSpace + 1, lastSpace - secondLastSpace - 1);
        statusStr = rest.substr(lastSpace + 1);
        
        std::string desc = rest.substr(0, secondLastSpace);
        
        size_t descStart = desc.find_first_not_of(" \t");
        if (descStart != std::string::npos)
        {
            desc = desc.substr(descStart);
        } else
        {
            std::cerr << "  Error in line " << lineNum << std::endl;
            errorCount++;
            continue;
        }
        
        try
        {
            priority = std::stoi(priorityStr);
        } catch (...)
        {
            std::cerr << "  Error in line " << lineNum << std::endl;
            errorCount++;
            continue;
        }
        
        size_t tasksBefore = tasks.size();
        addTask(tasks, pq, id, desc, priority);
        
        if (tasks.size() > tasksBefore)
        {
            addedCount++;
        } else
        {
            errorCount++;
        }
    }

    file.close();
    
    std::cout << "--- Statistics ---" << std::endl;
    std::cout << "Successfully added: " << addedCount << " tasks" << std::endl;
    std::cout << "Errors in the file: " << errorCount << std::endl;
    
    return true;
}