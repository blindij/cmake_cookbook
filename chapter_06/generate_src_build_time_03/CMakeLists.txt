cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(recipe-03 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PythonInterp QUIET REQUIRED)

# place generated code in the ${CMAKE_CURRENT_BINARY_DIR}/generated
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/generated)

# Default upper bound for the prime numbers
set(MAX_NUMBER "100" CACHE STRING "Upper bound for primes")

# Custom command to generate the header file
add_custom_command(
   OUTPUT
      ${CMAKE_CURRENT_BINARY_DIR}/generated/primes.hpp
   COMMAND
      ${PYTHON_EXECUTABLE} generate.py ${MAX_NUMBER}
      ${CMAKE_CURRENT_BINARY_DIR}/generated/primes.hpp
   WORKING_DIRECTORY
      ${CMAKE_CURRENT_SOURCE_DIR}
   DEPENDS
      generate.py
)

# add executable
add_executable(example "")
target_sources(example
   PRIVATE
      example.cpp
      ${CMAKE_CURRENT_BINARY_DIR}/generated/primes.hpp
)
target_include_directories(example
   PRIVATE
      ${CMAKE_CURRENT_BINARY_DIR}/generated
)
