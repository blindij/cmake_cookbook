# cmake
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(recipe-04 VERSION 2.0.1 LANGUAGES C)

# configure version.h
configure_file(
   version.h.in
   generated/version.h
   @ONLY
)

# add executable
add_executable(example example.c)
target_include_directories(example
   PRIVATE
      ${CMAKE_CURRENT_BINARY_DIR}/generated
)
