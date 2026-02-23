#include <fstream>
#include <unordered_map>

#ifndef GET_PENDING_TASKS
#define GET_PENDING_TASKS

void getPendingTasks(
    std::unordered_map<int, std::tuple<std::string, int, bool>>& tasks,
    std::ofstream& fileOut);

#endif