#ifndef CMPLTNG_TSK_HPP
#define CMPLTNG_TSK_HPP

#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>

void completeTopTask(
    std::priority_queue<std::tuple<int, int, std::string>>& prq,
    std::unordered_map<int, std::tuple<std::string, int, bool>>& tasks,
    std::stack<std::tuple<int, std::string, int>>& undoStack);

#endif