cmake_minimum_required(VERSION 3.10)
project(SmartDevicesChecker VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

# the following options prevent compiler-optimization issues that are unwanted in an edu process
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --- 1. Fetch Catch2 Dependency ---
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0 # Or latest version
)
FetchContent_MakeAvailable(Catch2)

# --- 2. Create a Library for shared logic ---
file(GLOB SOURCES "src/*.cpp") 
file(GLOB HEADERS "include/*.hpp")
add_library(Smart_Devices ${SOURCES} ${HEADERS})
target_include_directories(Smart_Devices PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src)

# --- 3. Main Application ---
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Smart_Devices)

# --- 4. Testing Setup ---
enable_testing()
file(GLOB TESTS "tests/*.cpp")
add_executable(tests ${TESTS})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain Smart_Devices)
target_include_directories(tests PRIVATE include)
include(Catch)
catch_discover_tests(tests)