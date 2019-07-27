cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(recipe-04 LANGUAGES CXX)
set(USE_LIBRARY OFF)
message(STATUS "Compile sources into a library? ${USE_LIBRARY}")
set(BUILD_SHARED_LIBS OFF)
list(APPEND _sources Message.hpp Message.cpp)

if(USE_LIBRARY)
# add_library will create a static library
# since BUILD_SHARED_LIBS is off
   add_library(message ${_sources})
   add_executable(hello_world hello-world.cpp)
   target_link_libraries(hello_world message)
else()
   add_executable(hello_world hello-world.cpp ${_sources})
endif()

add_library(message_objs
   OBJECT
      Message.hpp
      Message.cpp
)
