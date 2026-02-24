#include "CompletingTask.hpp"

// EXPECT: ordered queue
void completeTopTask(
    std::priority_queue<std::tuple<int, int, std::string>>& prq,
    std::unordered_map<int, std::tuple<std::string, int, bool>>& tasks,
    std::stack<std::tuple<int, std::string, int>>& undoStack)
{
    if(!prq.size())
    {
        std::cout << "Nothing to completing!" << "\n";
        return;
    }

    std::tuple<int, int, std::string> mjTask = prq.top();
    std::tuple<int, std::string, int> majorTaskForAdding =
        std::tuple(std::get<1>(mjTask),   // ID
                   std::get<2>(mjTask),   // info
                   std::get<0>(mjTask));  // priority

    undoStack.push(majorTaskForAdding);  // add task at the end of undoStack
    try                                  // change task's status in tasks
    {
        std::get<2>(tasks.at(std::get<0>(majorTaskForAdding))) = true;
    }
    catch(const std::out_of_range& e)
    {
        std::cout << "Task's ID not found\n";
    }

    prq.pop();  // pop first task from pq
    std::cout << "Completing task:\n"
              << "ID: " << std::get<1>(mjTask)
              << "\nInfo: " << std::get<2>(mjTask)
              << "\nPriority: " << std::get<0>(mjTask) << "\n";
    return;
}

// int main()
// {

// std::stack<std::tuple<int, std::string, int>> undoStack;
// std::unordered_map<int, std::tuple<std::string, int, bool>> tasks;
// std::priority_queue<std::tuple<int, int, std::string>> pq;

// tasks[1] = {"Go for a walk", 1, false};
// tasks[2] = {"Do homework in C++", 9, false};
// tasks[3] = {"Have a sleep", 7, false};

// pq.push({1, 1, "Go for a walk"});
// pq.push({9, 2, "Do homework in C++"});
// pq.push({7, 3, "Have a sleep"});

// completeTopTask(pq, tasks, undoStack);
// }