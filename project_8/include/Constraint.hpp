#ifndef CONSTRAINT_HPP
#define CONSTRAINT_HPP
#include <optional>
#include <string>
#include <typeindex>
struct Constraint
{
    std::string key;
    std::type_index expectedType;
    bool isRequired = false;
    std::optional<double> minValue;
    std::optional<double> maxValue;
};
#endif