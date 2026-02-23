#ifndef CMPLTNG_TSK_HPP
#define CMPLTNG_TSK_HPP

#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <iostream>


void completeTopTask(
    std::priority_queue<std::tuple<int, int, std::string>>& pq,
    std::unordered_map<int, std::tuple<std::string, int, bool>>& tasks,
    std::stack<std::tuple<int, std::string, int>>& undoStack);

#endif