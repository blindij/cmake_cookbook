cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(recipe-05 LANGUAGES CXX)
option(USE_LIBRARY "Compile sources into a library?" OFF)
message(STATUS "Compile sources into a library? ${USE_LIBRARY}")
# cmake_dependent_option() define options that depend
# on other options
include(CMakeDependentOption)

# second option depends on the value of the first
cmake_dependent_option(
  MAKE_STATIC_LIBRARY "Compile sources into a static library" OFF
  "USE_LIBRARY" ON
)

# third option depends on the value of the first
cmake_dependent_option(
  MAKE_SHARED_LIBRARY "Compile sources into a shared library" ON
  "USE_LIBRARY" ON
)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS_ON)
list(APPEND _sources Message.hpp Message.cpp)

if(USE_LIBRARY)
  message(STATUS "Compile sources into a STATIC library? ${MAKE_STATIC_LIBRARY}")
  message(STATUS "Compile sources into a SHARED library? ${MAKE_SHARED_lIbRARY}")

  if(MAKE_SHARED_LIBRARY)
   add_library(message SHARED ${_sources})
   add_executable(hello_world hello-world.cpp)
   target_link_libraries(hello_world message)
  endif(MAKE_SHARED_LIBRARY)

  if(MAKE_STATIC_LIBRARY)
    add_library(message STATIC ${_sources})
    add_executable(hello_world hello-world.cpp)
    target_link_libraries(hello_world message)
  endif(MAKE_STATIC_LIBRARY)
else(USE_LIBRARY)
   add_executable(hello_world hello-world.cpp ${_sources})
endif(USE_LIBRARY)

