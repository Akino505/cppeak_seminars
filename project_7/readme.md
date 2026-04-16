# Task 7 - Smart Home System

This is a C++ program for managing smart home devices through a central hub. It implements:

1. **Smart Light** - controllable brightness (0-100%)
2. **Thermostat** - temperature control (-30°C to +50°C)
3. **Security Camera** - mode switching (motion/continuous)

All devices inherit from an abstract `SmartDevice` base class with virtual methods:
- `turnOn()` / `turnOff()` - device-specific power control
- `configure()` - parameter parsing with validation
- `getStatus()` - device status
- `getId()` / `getName()` - device identification

The `HomeHub` class manages devices with:
- Unique ID validation
- Device registration (`addDevice`)
- Batch control (`activateAll`, `deactivateAll`)
- Status reporting (`generateReport`)
- Individual commands (`sendCommand` with "on"/"off"/configuration)

CMake was used for building, and Catch2 for unit tests.

## Device Configuration Syntax  

- **Smart Light**: `brightness=<0-100>`
- **Thermostat**: `temperature=<-30.0-50.0>`
- **Security Camera**: `mode=motion` or `mode=continuous`

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
./build/project_6
```
# Unit tests  
```bash
./build/tests
```
