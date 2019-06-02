# Required minimum cmake version
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# project name and languages
project(recipe_05 LANGUAGES CXX)

# settings...
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# create library example_library
add_library(example_library leaky_implementation.cpp)

# create executable
add_executable(cpp_test test.cpp)
target_link_libraries(cpp_test example_library)

# define MEMORY_CHECK COMMAND
find_program(MEMORYCHECK_COMMAND NAMES valgrind)
set(MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full")

# add memcheck test action
include(CTest)

enable_testing()

add_test(NAME cpp_test COMMAND $<TARGET_FILE:cpp_test>)
