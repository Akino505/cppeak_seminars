#include "ConfigValidator.hpp"
#include "Exception.hpp"
#include <any>

ConfigValidator::ConfigValidator(std::span<const Constraint> rules)
    : _rules(rules.begin(), rules.end())
{
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
        auto val = std::any_cast<double>(instruction->value);
        if(rule.minValue.has_value() && val < rule.minValue.value())
        {
            throw ConstraintViolationException(rule.key +
                                               " value is below minimum");
        }
        if(rule.maxValue.has_value() && val > rule.maxValue.value())
        {
            throw ConstraintViolationException(rule.key +
                                               " value is above maximum");
        }
    }
}