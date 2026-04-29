#include "ConfigStore.hpp"
#include "Setting.hpp"
#include <any>
#include <cstddef>
#include <optional>

ConfigStore::ConfigStore(size_t initialCapacity)
{
    _store.reserve(initialCapacity);
}

void ConfigStore::set(std::string_view key, std::any value)
{
    _store[std::string(key)] = std::move(value);
}

std::optional<Setting> ConfigStore::get(std::string_view key) const
{
    auto it = _store.find(std::string(key));
    if(it != _store.end())
        return Setting{it->first, it->second};
    return std::nullopt;
}