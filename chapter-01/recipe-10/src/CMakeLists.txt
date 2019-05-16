cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(recipe-10 LANGUAGES CXX)
add_library( geometry
   geometry_circle.hpp
   geometry_circle.cpp
   geometry_polygon.cpp
   geometry_polygon.hpp
   geometry_rhombus.cpp
   geometry_rhombus.hpp
   geometry_square.cpp
   geometry_square.hpp
)

target_compile_options(geometry
   PRIVATE
    -O3
)

list(
   APPEND sources_with_lower_optimization
      geometry_circle.cpp
      geometry_rhombus.cpp
)

message(STATUS "Setting source properties using IN LISTS syntax:")
foreach(_source IN LISTS sources_with_lower_optimization)
   set_source_files_properties(${_source} PROPERTIES COMPILE_FLAGS -O2)
   message(STATUS "Appending -O2 flag for ${_source}")
endforeach()

message(STATUS "Query sources properties using plain syntax:")
foreach(_source ${sourcw_with_lower_optimizatino})
   get_source_file_property(_flags ${_source} COMPILEFLAGS)
   message(STATUS "Source ${_source} has the following extra COMPILE_FLAGS: ${_flags}")
endforeach()

add_executable(compute-areas compute-areas.cpp)

target_link_libraries(compute-areas geometry)
