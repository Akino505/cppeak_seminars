#ifndef SETTING_HPP
#define SETTING_HPP
#include <any>
#include <string_view>
struct Setting
{
    std::string_view key;
    std::any value;
};
#endif