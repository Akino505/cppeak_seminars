#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <array>

std::vector<std::array<std::string, 4>> readFile(std::ifstream& file)
{
    std::string logComm = "";
    std::string comment = "";
    std::vector<std::array< std::string, 4>> logBase;
    while(std::getline(file, logComm))
    {
        std::array<std::string, 4> logLine;
        std::stringstream streamLog(logComm);
        for(int idx = 0; idx < 3; idx++)
        {
            streamLog >> logLine[idx];
        }
        std::getline(streamLog, comment);
        logLine[3] = comment;
        logBase.push_back(logLine);
    }
    file.close();
    return logBase;
}