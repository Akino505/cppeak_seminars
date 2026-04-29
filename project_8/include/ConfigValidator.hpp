#ifndef CONFIG_VALIDATOR_HPP
#define CONFIG_VALIDATOR_HPP
#include "ConfigStore.hpp"
#include "Constraint.hpp"
#include "Ivalidator.hpp"
#include <span>
#include <vector>
class ConfigValidator: public Ivalidator
{
public:
    explicit ConfigValidator(std::span<const Constraint> rules);
    void validate(const ConfigStore& config) const override;

private:
    std::vector<Constraint> _rules;
    void validateSingle(const std::string& key, const std::any& value) const;
};
#endif