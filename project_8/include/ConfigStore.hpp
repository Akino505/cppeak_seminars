#ifndef CONFIG_STORE_HPP
#define CONFIG_STORE_HPP
#include "Setting.hpp"
#include <any>
#include <cstddef>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>
class ConfigStore
{
public:
    explicit ConfigStore(size_t initialCapacity = 16);
    void set(std::string_view key, std::any value);
    std::optional<Setting> get(std::string_view key) const;
    const auto& data() const noexcept { return _store; }
    size_t size() const noexcept { return _store.size(); }

private:
    std::unordered_map<std::string, std::any> _store;
};
#endif