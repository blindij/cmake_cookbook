cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(recipe-03 LANGUAGES CXX)
add_executable(hello_world hello_world.cpp)
# define target compile definitions
target_compile_definitions(hello_world PUBLIC
    "COMPILER_NAME=\"${CMAKE_CXX_COMPILER_ID}\"")
if(CMAKE_CXX_COMPILER_ID MATCHES Intel)
    target_compile_definitions(hello_world PUBLIC "IS_INTEL_CXX_COMPILER") 
endif()
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    target_compile_definitions(hello_world PUBLIC "IS_GNU_CXX_COMPILER")
endif()
if(CMAKE_CXX_COMPILER_ID MATCHES XL)
    target_compile_definitions(hello_world PUBLIC "IS_XL_CXX_COMPILER")
endif()