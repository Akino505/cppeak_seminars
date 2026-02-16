cmake_minimum_required(VERSION 3.10.0)

project(project_3 CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 17)

# the following options prevent compiler-optimization issues that are unwanted in an edu process
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

# --- 1. Fetch Catch2 Dependency ---
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0 # Or latest version
)
FetchContent_MakeAvailable(Catch2)

# --- 2. Create a Library for shared logic ---
add_library(matrix_arithm
    src/appropriateSize.cpp
    src/inputSample.cpp
    src/meanDeviation.cpp
    src/median.cpp
    src/mode.cpp
    src/safeInput.cpp
    src/main.cpp)
target_include_directories(matrix_arithm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# --- 3. Main Application ---
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE matrix_arithm)


# --- 4. Testing Setup ---
enable_testing()

add_executable(tests src/tests.cpp
   src/appropriateSize.cpp
    src/inputSample.cpp
    src/meanDeviation.cpp
    src/median.cpp
    src/mode.cpp
    src/safeInput.cpp)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

target_include_directories(tests PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)