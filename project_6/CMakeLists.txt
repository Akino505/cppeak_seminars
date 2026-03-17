cmake_minimum_required(VERSION 3.10.0)

project(project_6 CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 17)

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
add_library(bd_employees ${SOURCES})
target_include_directories(bd_employees PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# --- 3. Main Application ---
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE bd_employees)


# --- 4. Testing Setup ---
enable_testing()

file(GLOB TESTS "tests/*.cpp")
add_executable(tests ${TESTS})

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain bd_employees)

target_include_directories(tests PRIVATE include)