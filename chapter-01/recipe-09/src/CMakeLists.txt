cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(recipe-09 LANGUAGES CXX)

# Request all library symbols to be exported on Windows
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Add target library
add_library(animals
   SHARED
      Animal.cpp
      Animal.hpp
      Cat.cpp
      Cat.hpp
      Dog.cpp
      Dog.hpp
      Factory.hpp
)

# Set Standard CXX extensions
set_target_properties(animals
   PROPERTIES
      CXX_STANDARD 14
      CXX_EXTENSION OFF
      CXX_STANDARD_REQUIRED ON
      POSITION_INDEPENDENT_CODE 1
)

# Add target executable
add_executable(animal-farm animal-farm.cpp)
set_target_properties(animal-farm
   PROPERTIES
      CXX_STANDARD 14
      CXX_EXTENSION OFF
      CXX_STANDARD_REQUIRED ON
)

# Linkd executable to the library
target_link_libraries(animal-farm animals)
