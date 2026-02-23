#include "addTask.hpp"
#include <iostream>      

void addTask(
    std::unordered_map<int, std::tuple<std::string, int, bool>>& tasks,
    std::priority_queue<std::tuple<int, int, std::string>>& prq,
    int taskId,
    const std::string& desc,
    int priority
)
{
    if (priority < 0 || priority > 10)
    {
        std::cerr << "Error: Priority must be in the range 0-10"
                  << std::endl;
        return;
    }

    if (tasks.find(taskId) != tasks.end())
    {
        std::cerr << "Error: Task with ID " << taskId << " already exists"
                  << std::endl;
        return;
    }

    if (desc.empty())
    {
        std::cerr << "Error: Description cannot be empty" << std::endl;
        return;
    }

    prq.push(std::make_tuple(priority, taskId, desc));
    tasks[taskId] = std::make_tuple(desc, priority, false);

    std::cout << "The task has been added successfully!" << std::endl;
}