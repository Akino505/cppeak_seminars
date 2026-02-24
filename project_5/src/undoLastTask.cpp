#include "CompletingTask.hpp"

// EXPECT: queue
void undoLast(
    std::stack<std::tuple<int, std::string, int>>& undoStack,
    std::unordered_map<int, std::tuple<std::string, int, bool>>& tasks,
    std::priority_queue<std::tuple<int, int, std::string>>& prq)
{
    if(!undoStack.size())
    {
        std::cout << "Nothing to undo!" << "\n";
        return;
    }

    std::tuple<int, std::string, int> mjTask = undoStack.top();
    std::tuple<int, int, std::string> taskForUndo =
        std::tuple(std::get<2>(mjTask),   // prioity
                   std::get<0>(mjTask),   // ID
                   std::get<1>(mjTask));  // info

    prq.push(taskForUndo);  // add task at the end of undoStack
    try                    // change task's status in tasks
    {
        std::get<2>(tasks.at(std::get<1>(taskForUndo))) = false;
    }
    catch(const std::out_of_range& e)
    {
        std::cout << "Task's ID not found\n";
    }

    undoStack.pop();  // pop first task from pq
    std::cout << "Undoing task:\n"
              << "ID: " << std::get<0>(mjTask)
              << "\nInfo: " << std::get<1>(mjTask)
              << "\nPriority: " << std::get<2>(mjTask) << "\n";

    return;
}

// int main()
// {
//     std::stack<std::tuple<int, std::string, int>> undoStack;
//     std::unordered_map<int, std::tuple<std::string, int, bool>> tasks;
//     std::priority_queue<std::tuple<int, int, std::string>> pq;

// tasks[1] = {"Go for a walk", 1, false};
// tasks[2] = {"Do homework in C++", 9, false};
// tasks[3] = {"Have a sleep", 7, false};

// undoStack.push({1, "Go for a walk", 1});
// undoStack.push({2, "Do homework in C++", 9});
// undoStack.push({3, "Have a sleep", 7});

// undoLast(undoStack, tasks, pq);
// }