cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(recipe-04 LANGUAGES CXX)
add_executable(arch_dependent arch_dependent.cpp)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_compile_definitions(arch_dependent PUBLIC "IS_64_BIT_ARCH")
    message(STATUS "Target is 64 bits")
else()
    target_compile_definitions(arch_dependent PUBLIC "IS_32_BIT_ARCH")
    message(STATUS "Target is 32 bits")
endif()
# Let the preprocessor know how about the host processor architecture
if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i386")
    message(STATUS "i386 architecture detected")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i686")
    message(STATUS "i686 architecture detected")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
    message(STATUS "x86_64 architecture deteced")
else()
    message(STATUS "host processor architecture is unknown")
endif()

target_compile_definitions(arch_dependent PUBLIC "ARCHITECTURE=${CMAKE_HOST_SYSTEM_PROCESSOR}")