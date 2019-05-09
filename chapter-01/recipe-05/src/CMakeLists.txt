cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(recipe-04 LANGUAGES CXX)
option(USE_LIBRARY "Compile sources into a library?" OFF)
set(BUILD_SHARED_LIBS OFF)
list(APPEND _sources Message.hpp Message.cpp)

if(USE_LIBRARY)
# add_library will create a static library
# since BUILD_SHARED_LIBS is off
   add_library(message ${_sources})
   add_executable(hello_world hello-world.cpp)
   target_link_libraries(hello_world message)
else(USE_LIBRARY)
   add_executable(hello_world hello-world.cpp ${_sources})
endif(USE_LIBRARY)

add_library(message_objs
   OBJECT
      Message.hpp
      Message.cpp
)
