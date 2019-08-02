cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(recipe-05 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Read version informatin from the file VERSION
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION")
   file(READ "${CMAKE_CURRENT_SOURCE_DIR}/VERSION" PROGRAM_VERSION)
   string(STRIP "${PROGRAM_VERSION}" PROGRAM_VERSION)
else()
   message(FATAL_ERROR "File ${CMAKE_CURRENT_SOURCE_DIR}/VERSION not found")
endif()

# configure the header file
configure_file(
   version.hpp.in
   generated/version.hpp
   @ONLY
)

# add_executable
add_executable(example example.cpp)
target_include_directories(example
   PRIVATE
      ${CMAKE_CURRENT_BINARY_DIR}/generated
)
