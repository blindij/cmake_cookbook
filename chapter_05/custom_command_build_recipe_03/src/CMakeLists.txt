# set the minimum required CMake version
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# project name and language
project(recipe_03 LANGUAGES CXX Fortran)

# Settings...
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# find the libraries
find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

# Declare variable
set(wrap_BLAS_LAPACK_sources
   ${CMAKE_CURRENT_BINARY_DIR}/wrap_BLAS_LAPACK/CxxBLAS.hpp
   ${CMAKE_CURRENT_BINARY_DIR}/wrap_BLAS_LAPACK/CxxBLAS.cpp
   ${CMAKE_CURRENT_BINARY_DIR}/wrap_BLAS_LAPACK/CxxLAPACK.hpp
   ${CMAKE_CURRENT_BINARY_DIR}/wrap_BLAS_LAPACK/CxxLAPACK.cpp
)

# extract the the wrap_BLAS_LAPACK.tar.gz
add_custom_command(
   OUTPUT 
      ${wrap_BLAS_LAPACK_sources}
   COMMAND 
      ${CMAKE_COMMAND} -E tar xzf ${CMAKE_CURRENT_SOURCE_DIR}/wrap_BLAS_LAPACK.tar.gz
   COMMAND 
      ${CMAKE_COMMAND} -E touch ${wrap_BLAS_LAPACK_sources}
   WORKING_DIRECTORY 
      ${CMAKE_CURRENT_BINARY_DIR}
   DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/wrap_BLAS_LAPACK.tar.gz
   COMMENT "Unpacking C++ wrappers for BLAS/LAPACK"
   VERBATIM
)

# add library
add_library(math "")
target_sources(math
   PRIVATE
      ${CMAKE_CURRENT_BINARY_DIR}/wrap_BLAS_LAPACK/CxxBLAS.cpp
      ${CMAKE_CURRENT_BINARY_DIR}/wrap_BLAS_LAPACK/CxxLAPACK.cpp
   PUBLIC
      ${CMAKE_CURRENT_BINARY_DIR}/wrap_BLAS_LAPACK/CxxBLAS.hpp
      ${CMAKE_CURRENT_BINARY_DIR}/wrap_BLAS_LAPACK/CxxLAPACK.cpp
)

target_include_directories(math
   INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/wrap_BLAS_LAPACK
)

target_link_libraries(math
   PUBLIC ${LAPACK_LIBRARIES}
)

# add executable
add_executable(linear_algebra linear_algebra.cpp)
target_link_libraries(linear_algebra
   PRIVATE math
)

