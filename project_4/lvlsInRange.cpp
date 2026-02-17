#include <iostream>
#include <string>

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

int lvlsInRange()
{
    std::ifstream fileIn("log_input.txt");
    std::ofstream fileOut("log_output.txt");
    std::vector<std::array<std::string, 4>> logBase = readFile(fileIn);
    std::vector<std::array<std::string, 2>> timeBase = {};
    int start = 0;
    int finish = 0;
    std::array<std::string, 2> timeLine = {};
    for(int idx = 0; idx < logBase.size(); idx++)
    {
        if(logBase[idx][1] != timeLine[0] || logBase[idx][2] != timeLine[1])
        {
            timeLine[0] = logBase[idx][1];
            timeLine[1] = logBase[idx][2];
            timeBase.push_back(timeLine);
        }
    }
    std::cout << "Choose the start time (type ONLY number):" << "\n";
    for(int idx = 0; idx < timeBase.size(); idx++)
    {
        std::cout << idx + 1 << " " << timeBase[idx][0] << " " << timeBase[idx][1] << "\n";
    }
    if(!(std::cin >> start) || start > timeBase.size() || start < 1)
    {
        std::cout << "Please, type appropriate number." << "\n";
        return 0;
    }
    std::cout << "Choose the finish time (type ONLY number):" << "\n";
    for(int idx = start - 1; idx < timeBase.size(); idx++)
    {
        std::cout << idx + 1 << " " << timeBase[idx][0] << " " << timeBase[idx][1] << "\n";
    }
    if(!(std::cin >> finish) || finish > timeBase.size() || finish < 1)
    {
        std::cout << "Please, type appropriate number." << "\n";
        return 0;
    }
    for(int idx = start - 1; idx < finish; idx++)
    {
        for(int jdx = 0; jdx < logBase.size(); jdx++)
        {
            if(logBase[jdx][1] == timeBase[idx][0] && logBase[jdx][2] == timeBase[idx][1])
            {
                fileOut << logBase[jdx][0] << " " << logBase[jdx][1] << " " << logBase[jdx][2] << " " << logBase[jdx][3] << "\n";
            }
        }
    }
    return 1;
}


int main()
{
    lvlsInRange();
}