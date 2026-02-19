#include "statisticForPeriod.hpp"
#include "countLvls.hpp"


bool lvlsInRange2(std::vector<std::array<std::string, 4>> logBase, std::ofstream& out)
{
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
        return false;
    }
    std::cout << "Choose the finish time (type ONLY number):" << "\n";
    for(int idx = start - 1; idx < timeBase.size(); idx++)
    {
        std::cout << idx + 1 << " " << timeBase[idx][0] << " " << timeBase[idx][1] << "\n";
    }
    if(!(std::cin >> finish) || finish > timeBase.size() || finish < 1)
    {
        std::cout << "Please, type appropriate number." << "\n";
        return false;
    }
    out << "Result of command 4." << std::endl;
    out << "from: " << timeBase[start - 1][0] << " " << timeBase[start - 1][1] << std::endl;
    out << "to: " << timeBase[finish - 1][0] << " " << timeBase[finish - 1][1] << std::endl;

    std::vector<std::array<std::string, 4>> newVect;
    newVect.assign(logBase.begin() + start - 1, logBase.begin() + finish);
    countLvls(newVect, out);
    return true;
}
