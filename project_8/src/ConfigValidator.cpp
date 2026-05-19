#include "ConfigValidator.hpp"
#include "Exception.hpp"
#include <any>

ConfigValidator::ConfigValidator(std::span<const Constraint> rules)
    : _rules(rules.begin(), rules.end())
{
}

void checkBoundaries(const auto& rule, const auto& val)
{
    if(rule.minValue.has_value() && val < rule.minValue.value())
        throw ConstraintViolationException(rule.key +
                                           " value is less than minimum");
    if(rule.maxValue.has_value() && val > rule.maxValue.value())
        throw ConstraintViolationException(rule.key +
                                           " value is greater than maximum");
}

void ConfigValidator::validate(const ConfigStore& config) const
{
    for(const auto& rule: _rules)
    {
        auto instruction = config.get(rule.key);
        // required
        if(!instruction.has_value())
        {
            if(rule.isRequired)
            {
                throw MissingRequiredFieldException("Missing required field: " +
                                                    rule.key);
            }
            continue; //empty std::optional - UB
        }
        // type
        if(instruction->value.type() != rule.expectedType)
        {
            throw InvalidKeyTypeException(
                "Field " + rule.key + " expected type " +
                rule.expectedType.name() + ", but got " +
                instruction->value.type().name());
        }
        // min & max
        if(rule.expectedType == typeid(int) ||
           rule.expectedType == typeid(double))
        {
            if(rule.expectedType == typeid(int))
            {
                int val = std::any_cast<int>(instruction->value);
                checkBoundaries(rule, val);
            }
            else
            {
                auto val = std::any_cast<double>(instruction->value);
                checkBoundaries(rule, val);
            }
        }
    }
}