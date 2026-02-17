#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <string>

int countLvls(std::vector<std::array<std::string, 4>> logBase, std::fstream& Out)
{
    int errs = 0;
    int warns = 0;
    int dbgs = 0;
    int infos = 0;
    for(int idx = 0; idx < logBase.size(); idx++)
    {
        if(logBase[idx][0] == "ERROR") errs++;
        if(logBase[idx][0] == "DEBUG") dbgs++;
        if(logBase[idx][0] == "WARNING") warns++;
        if(logBase[idx][0] == "INFO") infos++;   
    }
}

int main()
{
    std::fstream fileIn("log_input.txt");
    std::fstream fileOut("log_output.txt");
}