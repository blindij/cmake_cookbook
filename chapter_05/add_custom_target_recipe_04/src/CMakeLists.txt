# The required minimum version of CMake
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# The languages and project name
project(recipe_04 LANGUAGES CXX Fortran)

# Settings...
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# include CMakeLists.txt from subdirectory deps
add_subdirectory(deps)

# executable target
add_executable(linear_algebra linear_algebra.cpp)
target_link_libraries(linear_algebra
  PRIVATE
    math
)

