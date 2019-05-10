cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(recipe-08 LANGUAGES CXX)
message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")
list(APPEND flags "-fPIC" "-Wall")
if(NOT WIN32)
   list(APPEND flags "-Wextra" "-Wpedantic")
endif(NOT WIN32)
add_library(geometry
   STATIC
   geometry_circle.cpp
)

# we set compile options for this library target:
target_compile_options(geometry
   PRIVATE
   ${flags}
)

# we add a target for the executable
add_executable(compute-areas compute-areas.cpp)

# we set compile options for the executable
target_compile_options(compute-areas
   PRIVATE
      "-fpic"
)

# we link the executable to the library
target_link_libraries(compute-areas geometry)
