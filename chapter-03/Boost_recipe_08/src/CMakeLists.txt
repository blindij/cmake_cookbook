# The required minimum version of CMake
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# The project name and compile language used
project(Boost_recipe_08 LANGUAGES CXX)

# Settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Go searching for Boost
find_package(Boost 1.54 REQUIRED COMPONENTS filesystem)

# Add executable
add_executable(path_info path_info.cpp)

# Link to the Boost library component
target_link_libraries(path_info
   PUBLIC
      Boost::filesystem
)

