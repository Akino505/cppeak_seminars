#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>

#ifndef READ_FILE
#define READ_FILE

bool readTasksFromFile(
    const std::string& filename,
    std::unordered_map<int, std::tuple<std::string, int, bool>>& tasks,
    std::priority_queue<std::tuple<int, int, std::string>>& pq);

#endif