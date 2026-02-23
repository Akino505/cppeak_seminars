#include <iostream>      
#include <fstream>       
#include <string>        
#include <tuple>         
#include <queue>         
#include <unordered_map> 
#include <sstream>       
#include <algorithm>     

#ifndef READ_FILE
#define READ_FILE

bool readTasksFromFile(const std::string& filename, 
                       std::unordered_map<int, std::tuple<std::string, int, bool>>& tasks,
                       std::priority_queue<std::tuple<int, int, std::string>>& pq,
                       int& nextId);

#endif