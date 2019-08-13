# require minimum CMake version
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# project name and languages
project(recipe_07 LANGUAGES CXX)

# settings...
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# A list of flags to be always present
list(APPEND CXX_BASIC_FLAGS "-g3" "-O1")

# Include module for checking whether  the CXX compiler
# supports a given flag
include(CheckCXXCompilerFlag)

# Set variable holding flags for the address sanitizer
set(ASAN_FLAGS "-fsanitize=address -fno-omit-frame-pointer")

# CMAKE_REQUIRED_FLAGS is used by check_cxx_compiler_flag
set(CMAKE_REQUIRED_FLAGS ${ASAN_FLAGS})
check_cxx_compiler_flag(${ASAN_FLAGS} asan_works)
unset(CMAKE_REQUIRED_FLAGS)

#if the flags works, do string substitution
if(asan_works)
      string(REPLACE " " ";" _asan_flags ${ASAN_FLAGS})

# add executable
add_executable(asan-example asan-example.cpp)

# set compiler flags for the executable - basic and sanitizer flags
target_compile_options(asan-example
   PUBLIC
      ${CXX_BASIC_FLAGS}
      ${_asan_flags}
      )

# set the flags also for the linker
target_link_libraries(asan-example PUBLIC ${_asan_flags})
endif()
