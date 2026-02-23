#include "addTask.hpp"

void addTask(
    std::unordered_map<int, std::tuple<std::string, int, bool>>& tasks,
    std::priority_queue<std::tuple<int, int, std::string>>& pq,
    int id,
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

    if (tasks.find(id) != tasks.end())
    {
        std::cerr << "Error: Task with ID " << id << " already exists"
                  << std::endl;
        return;
    }

    if (desc.empty())
    {
        std::cerr << "Error: Description cannot be empty" << std::endl;
        return;
    }

    pq.push(std::make_tuple(priority, id, desc));
    tasks[id] = std::make_tuple(desc, priority, false);

    std::cout << "The task has been added successfully!" << std::endl;
}