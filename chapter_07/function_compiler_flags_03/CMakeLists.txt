cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(recipe_03 LANGUAGES C CXX)
include(cmake/set_compiler_flag.cmake)
# try a list of C flags
set_compiler_flag(
  working_compile_flag C REQUIRED
  "-foo" 
  "-wrong"
  "-wrong"
  "-Wall"
  "-warn all"
  "-Minfotm=inform"
  "-nope"
)

message(STATUS "working C compile flag: ${working_compile_flag}")

# try a list of C++ flags
set_compiler_flag(
  working_compile_flag CXX REQUIRED
  "-foo"
  "-g"
  "/RTCcsu"
)

message(STATUS "working CXX compile flags: ${working_compile_flag}")
