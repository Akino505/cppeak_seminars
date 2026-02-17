#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <string>
#include <sstream>

int countLvls(std::vector<std::array<std::string, 4>> logBase, std::ofstream& out)
{
    int errs = 0;
    int warns = 0;
    int dbgs = 0;
    int infos = 0;
    for(int idx = 0; idx < logBase.size(); idx++)
    {
        if(logBase[idx][0] == "ERROR") errs++;
        else if(logBase[idx][0] == "DEBUG") dbgs++;
        else if(logBase[idx][0] == "WARNING") warns++;
        else if(logBase[idx][0] == "INFO") infos++;   
    }
    out << "ERRORS: " << errs << "\n";
    out << "DEBUGS: " << dbgs << "\n";
    out << "WARNINGS: " << warns << "\n";
    out << "INFOS: " << infos << "\n";
    return 0;
}