#ifndef UNDO_LST_TSK_HPP
#define UNDO_LST_TSK_HPP

#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>

void undoLast(
    std::stack<std::tuple<int, std::string, int>>& undoStack,
    std::unordered_map<int, std::tuple<std::string, int, bool>>& tasks,
    std::priority_queue<std::tuple<int, int, std::string>>& pq);

#endif