cmake_minimum_required(VERSION 3.10.0)

project(project_9 CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

file(GLOB LIBRARY_SOURCES "${SRC_DIR}/*.cpp")
# Исключаем main.cpp из библиотеки
list(REMOVE_ITEM LIBRARY_SOURCES "${SRC_DIR}/main.cpp")

file(GLOB LIBRARY_HEADERS "${INCLUDE_DIR}/*.hpp")

add_library(Recor_Buffer ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(Recor_Buffer PUBLIC ${INCLUDE_DIR})

add_executable(${CMAKE_PROJECT_NAME} ${SRC_DIR}/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Recor_Buffer)

enable_testing()

file(GLOB TEST_SOURCES "${TESTS_DIR}/*.cpp")

if(TEST_SOURCES)
    add_executable(tests ${TEST_SOURCES})
    target_link_libraries(tests PRIVATE Catch2::Catch2WithMain Recor_Buffer)
    target_include_directories(tests PRIVATE ${INCLUDE_DIR})
    include(Catch)
    catch_discover_tests(tests)
endif()