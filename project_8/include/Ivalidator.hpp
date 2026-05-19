#ifndef IVALIDATOR_HPP
#define IVALIDATOR_HPP
#include "ConfigStore.hpp"
struct Ivalidator
{
    virtual ~Ivalidator() = default;
    virtual void validate(const ConfigStore& config) const = 0;
};
#endif