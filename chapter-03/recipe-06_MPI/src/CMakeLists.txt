# Set the minimum CMake version
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# Project name and languages
project(recipe-06_MPI LANGUAGES CXX)

# Settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Search for MPI
find_package(MPI REQUIRED)

# Add executable
add_executable(hello_mpi hello_mpi.cpp)

# Link with the MPI library
target_include_directories(hello_mpi
   PUBLIC
      MPI::MPI_CXX
)
