cmake_minimum_required(VERSION 3.10.0)
project(Project_1 LANGUAGES CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type") 

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)


add_executable(Project_1
    src/main.cpp
    src/mult.cpp
    include/mult.h
)

target_include_directories(Project_1 PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(tests
    src/tests.cpp
    src/mult.cpp
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

target_include_directories(tests PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)