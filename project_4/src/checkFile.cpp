#include "checkFile.hpp"

bool checkFile(std::ifstream& inputFile) {
    if (!inputFile.is_open()) {
        std::cout << "Error: File not found" << "\n";
        return false;
    }

    return true;
}