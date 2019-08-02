cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(recipe_06 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD ON)

# in case Git si not available, we default to "unknown"
set(GIT_HASH "unknown")

# find Git and if availabel set GIT_HASH variable
find_package(Git QUIET)
if(GIT_FOUND)
   execute_process(
      COMMAND ${GIT_EXECUTABLE} log -1 --pretty=format:%h
      OUTPUT_VARIABLE GIT_HASH
      OUTPUT_STRIP_TRAILING_WHITESPACE
      ERROR_QUIET
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
   )
endif()

message(STATUS "Git hash is ${GIT_HASH}")

# generate file version.hpp based on version.hpp.in
configure_file(
   version.hpp.in
   generated/version.hpp
   @ONLY
)

# example code
add_executable(example example.cpp)

# needs to find the generated header file
target_include_directories(example
   PRIVATE
      ${CMAKE_CURRENT_BINARY_DIR}/generated
)
