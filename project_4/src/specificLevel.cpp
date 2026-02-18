#include "specificLevel.hpp"

bool specificLevel(std::vector<std::array<std::string, 4>> logBase,
                   std::ofstream& out)
{
    int level = 0;
    std::cout << "Choose the level: 1 - INFO, 2 - WARNING, 3 - ERROR, 4 - "
                 "DEBUG (type ONLY number):"
              << "\n";
    std::cin >> level;
    if((level < 1) || (level > 4))
    {
        std::cout << "Please, type appropriate number." << "\n";
        return false;
    }

    static std::map<std::string, int> levelMap = {
        {"INFO", 1}, {"WARNING", 2}, {"ERROR", 3}, {"DEBUG", 4}};

    int counter = 0;
    while(counter < logBase.size())
    {
        if(levelMap[logBase[counter][0]] == level)
        {
            out << logBase[counter][0] << " " << logBase[counter][1] << " "
                << logBase[counter][2] << " " << logBase[counter][3] << "\n";
        }
        counter++;
    }
    return true;
}