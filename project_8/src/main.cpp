#include "ConfigStore.hpp"
#include <iostream>
#include <stdexcept>

int main() {
    // ✅ explicit работает: ConfigStore store(32); — OK
    // ConfigStore store = 32; — ОШИБКА компиляции
    ConfigStore store(64);

    store.set("server.port", 8080);
    store.set("db.host", std::string("localhost"));
    store.set("debug.enabled", true);

    // ✅ Безопасное чтение через optional + any_cast
    if (auto opt = store.get("server.port")) {
        try {
            int port = std::any_cast<int>(opt->value);
            std::cout << "Port: " << port << "\n";
        } catch (const std::bad_any_cast& e) {
            std::cerr << "Type mismatch: " << e.what() << "\n";
        }
    } else {
        std::cout << "Key 'server.port' not found\n";
    }

    // ❌ Ключа нет → optional пустой
    auto missing = store.get("non.existent");
    if (!missing) {
        std::cout << "Missing key handled gracefully\n";
    }
}