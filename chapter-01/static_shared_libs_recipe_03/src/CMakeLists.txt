cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(recipe-01 LANGUAGES CXX)
add_library(message_objs
   OBJECT
      Message.hpp
      Message.cpp
)
# Only needed for older compilers
set_target_properties(message_objs
   PROPERTIES
      POSITION_INDEPENDENT_CODE 1
)

add_library(message_shared
   SHARED
      $<TARGET_OBJECTS:message_objs>
)

add_library(message_static
   STATIC
      $<TARGET_OBJECTS:message_objs>
)

add_executable(hello-world hello-world.cpp)

target_link_libraries(hello-world message_static)
