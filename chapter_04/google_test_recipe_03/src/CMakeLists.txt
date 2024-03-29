# set minimum cmake version
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# set project name and language
project(recipe_03 LANGUAGES CXX)

# settings - require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# example library
add_library(sum_integers sum_integers.cpp)

# main code
add_executable(sum_up main.cpp)
target_link_libraries(sum_up sum_integers)

# Check for ENABLE_UNIT_TESTS
option(ENABLE_UNIT_TESTS "Enable unit tests" ON)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")

if(ENABLE_UNIT_TESTS)
   include(FetchContent)
   FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG release-1.8.0
   )

   FetchContent_GetProperties(googletest)
   if(NOT googletest_POPULATED)
      FetchContent_Populate(googletest)

      # Prevent GoogleTest from overriding our compiler/linker option
      # when building with Visual Studio
      set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
      # Prevent GoogleTest from using PThreads
      set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)

      # adds the targers: gtest, gtest_main, gmock, gmock_main
      add_subdirectory(
         ${googletest_SOURCE_DIR}
         ${googletest_BINARY_DIR}
      )
      # silence std::tr1 warning on MSVC
#      if (MSVC)
#         foreach(_tgt gtest gtest_main gmock gmock_main)
#            target_compile_definitions(${_tgt}) PRIVATE "_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING")
#         endforeach()
#      endif()
   endif()
   add_executable(cpp_test "")
   target_sources(cpp_test PRIVATE test.cpp)
   target_link_libraries(cpp_test PRIVATE sum_integers gtest_main)

   enable_testing()

   add_test(NAME google_test COMMAND $<TARGET_FILE:cpp_test>)
endif()

