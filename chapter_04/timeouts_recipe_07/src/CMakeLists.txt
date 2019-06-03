# set minimum cmake version
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# project name and language
project(recipe_07 LANGUAGES NONE)

# detect python
find_package(PythonInterp REQUIRED)

# define tests
enable_testing()

# we expect this test to run for 2 seconds
add_test(example ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test.py)

# Specify a TIMEOUT for the test
set_tests_properties(example PROPERTIES TIMEOUT 10)

