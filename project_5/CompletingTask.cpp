#include "CompletingTask.hpp"

// EXPECT: ordered queue
void completeTopTask(
    std::priority_queue<std::tuple<int, int, std::string>>& pq,
    std::unordered_map<int, std::tuple<std::string, int, bool>>& tasks,
    std::stack<std::tuple<int, std::string, int>>& undoStack)
{
    if(!pq.size())
    {
        std::cout << "Nothing to completing!" << "\n";
        return;
    }

    std::tuple<int, int, std::string> mjTask = pq.top();
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

    pq.pop();  // pop first task from pq

    return;
}

// int main()
// {
//     std::priority_queue<int> pq;
//     pq.push(30);
//     pq.push(10);
//     pq.push(20);
//     std::cout << pq.top() << "\n";
//     pq.pop();
//     std::cout << pq.top() << "\n";
// }