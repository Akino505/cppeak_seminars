#include "readFile.hpp"

bool readTasksFromFile(const std::string& filename, 
                       std::unordered_map<int, std::tuple<std::string, int, bool>>& tasks,
                       std::priority_queue<std::tuple<int, int, std::string>>& pq,
                       int& nextId)
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
        std::string desc;
        int priority;
        std::string statusStr;

        if (!(iss >> id >> desc >> priority >> statusStr))
        {
            std::cerr << "  Error in line " << lineNum << std::endl;
            errorCount++;
            continue;
        }

        std::string remaining;
        if (iss >> remaining)
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
            if (id >= nextId)
            {
                nextId = id + 1;
            }
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