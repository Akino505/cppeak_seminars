# Task 8

This is a C++ program for loading, validating, and storing application settings.  
Architecture components:  
1. **Setting** - `key + value` pair (`std::string_view` + `std::any`)  
2. **ConfigStore** - storage in `std::unordered_map`, accessed via `get()` - `std::optional<Setting>`  
3. **ConfigValidator** - checks types, ranges, and required fields via `std::span<const Constraint>`  
4. **IValidator** - pure virtual interface for custom validation strategies  
5. **ConfigLoader** - File/string parsing, returns `std::expected<Config, ConfigError>`   
CMake was used for building, and Catch2 for unit tests.  
# Build
### Configuration (setup) of the project  
```bash
cmake -S . -B build
```
### Build the project
```bash
cmake --build build
```
# Run  
```bash
./build/project_8
```
# Unit tests  
```bash
./build/tests
```
