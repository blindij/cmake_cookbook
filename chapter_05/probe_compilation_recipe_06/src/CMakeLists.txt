# require minimum version of CMake
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# set project name and language
project(recipe_06 LANGUAGES CXX)

# settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# search for OpenMP support
find_package(OpenMP)

if (OpenMP_FOUND)
    # set at scratch directory used for probe compiling
    set(_scratch_dir ${CMAKE_CURRENT_BINARY_DIR}/omp_try_compile)
    try_compile( omp_taskloop_test_1
        ${_scratch_dir}
        SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/taskloop.cpp
        LINK_LIBRARIES
            OpenMP::OpenMP_CXX
    )
    include(CheckCXXSourceCompiles)
    file(READ ${CMAKE_CURRENT_SOURCE_DIR}/taskloop.cpp _snippet)
    set(CMAKE_REQUIRED_LIBRARIES OpenMP::OpenMP_CXX)
    check_cxx_source_compiles("${_snippet}" omp_taskloop_test_2)
    unset(CMAKE_REQUIRED_LIBRARIES)
    message(STATUS "Result of check_cxx_source_complies: ${omp_taskloop_test_2}")
else()
    message(STATUS "OpenMP not found: no test for taskloop is run.")
endif()
