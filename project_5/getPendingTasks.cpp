#include "getPendingTasks.hpp"

bool comparePriority(
    const std::pair<int, std::tuple<std::string, int, bool>>& first,
    const std::pair<int, std::tuple<std::string, int, bool>>& second)
{
    return std::get<1>(first.second) > std::get<1>(second.second);
}

void getPendingTasks(
    std::unordered_map<int, std::tuple<std::string, int, bool>>& tasks,
    std::ofstream& fileOut)
{
    std::vector<std::pair<int, std::tuple<std::string, int, bool>>> vectTasks(
        tasks.begin(), tasks.end());
    std::sort(vectTasks.begin(), vectTasks.end(), comparePriority);
    for(const auto& elem: vectTasks)
    {
        int id = elem.first;
        const auto& task = elem.second;
        fileOut << "ID: " << id << " Task: " << std::get<0>(task)
                << " Priority: " << std::get<1>(task) << std::endl;
    }
}