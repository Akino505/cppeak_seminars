#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <array>

std::vector<std::array< std::string, 4>> readFile(std::ifstream& file)
{
    std::string logComm = "";
    std::array<std::string, 4> logLine;
    std::vector<std::array< std::string, 4>> logBase;
    while(std::getline(file, logComm))
    {
        std::stringstream streamLog(logComm);
        for(int idx = 0; idx < 4; idx++)
        {
            streamLog >> logLine[idx];
        }
        logBase.push_back(logLine);
    }
    file.close();
    return logBase;
}