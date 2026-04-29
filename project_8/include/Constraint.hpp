#ifndef CONSTRAINT_HPP
#define CONSTRAINT_HPP
#include <optional>
#include <string>
struct Constraint
{
    std::string key;
    bool isRequired = false;
    bool checkType = false;
    std::optional<int> minValue;
    std::optional<int> maxValue;
};
#endif