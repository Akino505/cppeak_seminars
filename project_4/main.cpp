#include <iostream>
#include <fstream>
#include <array>

std::ostream& operator<<(std::ostream& os, const std::array<std::string, 4>& arr)
{
    os << arr[0] << " " << arr[1] << " " << arr[2] << arr[3] << "\n";
    return os;
}

int main()
{
    std::fstream file("log_input.txt");
}