# The minimum CMake version required
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# The project name and compile language
project(zmq_recipe_09 LANGUAGES C)

# Settings
set(CMAKE_CXX_STANDARD 99)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Go searching for a package 
find_package(PkgConfig REQUIRED QUIET)

# Use the general search module
pkg_search_module(
   ZeroMQ
   REQUIRED
      libzeromq libzmq libOmq
   IMPORTED_TARGET
)

# Print a message 
if(TARGET PkgConfig::ZeroMQ)
   message(STATUS "Found ZeroMQ")
endif()

# Add two executables
add_executable(hwserver hwserver.c)
target_link_libraries(hwserver PkgConfig::ZeroMQ)
add_executable(hwclient hwclient.c)
target_link_libraries(hwclient PkgConfig::ZeroMQ)


