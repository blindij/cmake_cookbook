# The minimum required version of CMake
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# Project name, language specification
project(recipe-05 LANGUAGES CXX)

# Settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Go searching for OpenMP
find_package(OpenMP REQUIRED)

# Add executable...
add_executable(example example.cpp)

target_link_libraries(example
   PUBLIC
      OpenMP::OpenMP_CXX
)


