#include <string>        
#include <tuple>        
#include <queue>         
#include <unordered_map> 

#ifndef ADD_TASK
#define ADD_TASK

void addTask(std::unordered_map<int, std::tuple<std::string, int, bool>>& tasks, 
             std::priority_queue<std::tuple<int, int, std::string>>& prq, 
             int taskId, const std::string& desc, int prio);

#endif