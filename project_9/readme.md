# Task 9 - Database Record Table

This is a C++ program for managing database records through a table-based storage system. It implements:

1. **UserRecord** - stores user information (id, name)
2. **LogRecord** - stores event logs (event description)

All records inherit from an abstract `Record` base class with virtual methods:
- `toString()` - returns record type identifier ("User", "Log")
- `type()` - returns human-readable state of the object
- `serialize()` - writes record fields to a linear memory buffer
- `deserialize()` - reads record fields from a memory buffer

The `RecordBuffer` class manages raw memory with:
- Alignment support via `std::align`
- Rule of 5 (destructor, copy/move constructors, copy/move assignment)
- Copy-and-swap idiom using `std::unique_ptr` for exception safety

The `Table` class aggregates records with:
- Rule of 0 (compiler-generated special members)
- `RecordBuffer` for byte-level batch operations
- `std::vector<std::shared_ptr<Record>>` for polymorphic record storage
- Reference counting demonstration via `shared_ptr`

CMake was used for building, and Catch2 for unit tests.
## Key Implementation Details

- **Rule of 5** for `RecordBuffer` - manual resource management
- **Rule of 0** for `Table` - relies on member constructors
- **Copy-and-swap** idiom in `operator=` for strong exception guarantee
- **`std::align`** for memory alignment
- **`std::shared_ptr`** for shared ownership tracking
- **Virtual destructor** in `Record` for proper cleanup
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
./build/project_9
```
# Unit tests  
```bash
./build/tests
```
