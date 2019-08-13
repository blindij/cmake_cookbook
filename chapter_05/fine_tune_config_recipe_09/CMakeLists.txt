# Minimum cmake version
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# Project name and languages
project(recipe_09 LANGUAGES CXX)

# Settings...
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(USE_MPI "Use MPI parallelization" ON)

if(USE_MPI)
   find_package(MPI REQUIRED)
endif()

add_executable(example example.cpp)
target_link_libraries(example
   PUBLIC
      $<$<BOOL:${MPI_FOUND}>:MPI::MPI_CXX>
   )
target_compile_definitions(example
   PRIVATE
      $<$<BOOL:${MPI_FOUND}>:HAVE_MPI>
   )

if (MPI_FOUND)
   include(CMakePrintHelpers)
   cmake_print_properties(
      TARGETS MPI::MPI::CXX
      PROPERTIES INTERFACE_LINK_LIBRARIES
   )
endif()
