#include "checkFile.hpp"

bool checkFile(std::fstream& inputFile) {
    if (!inputFile.is_open()) {
        std::cout << "Error: File not found" << std::endl;
        return false;
    }

    return true;
}