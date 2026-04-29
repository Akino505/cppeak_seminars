#ifndef CONFIG_EXCEPTION_HPP
#define CONFIG_EXCEPTION_HPP

#include <exception>
#include <string>
class ConfigException: public std::exception
{
public:
    explicit ConfigException(std::string msg): _msg(std::move(msg)) {}
    const char* what() const noexcept override { return _msg.c_str(); }

protected:
    std::string _msg;
};

class FileAccessDeniedException: public ConfigException
{
    using ConfigException::ConfigException;
};
class InvalidKeyTypeException: public ConfigException
{
    using ConfigException::ConfigException;
};
class ConstraintViolationException: public ConfigException
{
    using ConfigException::ConfigException;
};
class MissingRequiredFieldException: public ConfigException
{
    using ConfigException::ConfigException;
};
#endif