cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(recipe-06 LANGUAGES C CXX)

message(STATUS "Is the C++ compiler loaded? ${CMAKE_CXX_COMPILER_LOADED}")

if(CMAKE_CXX_COMPILER_LOADED)
  message(STATUS "The C++ compiler ID is: ${CMAKE_CXX_COMPILER_ID}")
  message(STATUS "Is the C++ from GNU? ${CMAKE_COMPILER_ID}")
  message(STATUS "Is the C++ compiler version is: ${CMAKE_CXX_COMPILER_VERSION}")
endif(CMAKE_CXX_COMPILER_LOADED)

message(STATUS "Is the C compiler loaded? ${CMAKE_C_COMPILER_LOADED}")
if(CMAKE_C_COMPILER_LOADED)
  message(STATUS "The C compiler ID is: ${CMAKE_C_COMPILER_ID}")
  message(STATUS "Is the C from GNU? ${CMAKE_COMPILER_IS_GNUCC}")
  message(STATUS "The C compiler version is: ${CMAKE_C_COMPILER_VERSION}")
endif(CMAKE_C_COMPILER_LOADED)
