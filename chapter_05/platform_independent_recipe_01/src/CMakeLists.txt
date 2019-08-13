# require minimum version of cmake
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# define project name and set compile languages
project(recipe_01 LANGUAGES CXX)

# language settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add custom target, which will extract the archive inside the build directory
add_custom_target(unpack_eigen
  ALL 
    COMMAND
      ${CMAKE_COMMAND} -E tar jxf ${CMAKE_CURRENT_SOURCE_DIR}/eigen-eigen-5a0156e40feb.tar.bz2
    COMMAND
      ${CMAKE_COMMAND} -E rename eigen-eigen-5a0156e40feb eigen-3.3.4
    WORKING_DIRECTORY
      ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT
      "Unpacking Eigen3 in ${CMAKE_CURRENT_BINARY_DIR}/eigen-3.3.4"
)

# Executable target based on our source file
add_executable(linear_algebra linear_algebra.cpp)
# State the dependency on Eigen explicitly
add_dependencies(linear_algebra unpack_eigen)
target_include_directories(linear_algebra PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}/eigen-3.3.4
)


