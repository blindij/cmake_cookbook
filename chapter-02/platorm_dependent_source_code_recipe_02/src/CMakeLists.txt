cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(recipe-02 LANGUAGES CXX)
add_executable(hello_world hello_world.cpp)
# Preprocessor knows the system name
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_definitions(hello_world PUBLIC "IS_LINUX")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_compile_definitions(hello_world PUBLIC "IS_MACOS")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_definitions(hello_world PUBLIC "IS_WINODWS")
endif()