# The cmake version required
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# The project name and the program languages
project(recipe-04 LANGUAGES CXX C Fortran)

# Settings for C++. We want C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Verify that Fortran and C++ work together
include(FortranCInterface)
FortranCInterface_VERIFY(CXX)
FortranCInterface_HEADER(
   fc_mangle.h
   MACRO_NAMESPACE "FC_"
   SYMBOLS DSCAL DGESV
)

# CMake must find libraries BLAS and LAPACK
find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

# Add library with sources for the BLAS and LAPACK wrappers
add_library(math "")

target_sources(math
   PRIVATE
      CxxBLAS.cpp
      CxxLAPACK.cpp
)

target_include_directories(math
   PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}
      ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(math
   PUBLIC
      ${LAPACK_LIBRARIES}
)

# add executable and link it to math
add_executable(linear_algebra "")

target_sources(linear_algebra 
   PRIVATE
      linear_algebra.cpp
)

target_link_libraries(linear_algebra
   PRIVATE
      math
)
