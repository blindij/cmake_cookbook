# minimum required cmake version
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# project and languages
project(recipe_06 LANGUAGES NONE)

find_package(PythonInterp REQUIRED)

# define test 
enable_testing()

add_test(example ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test.py)

# Here we set that the test is exepected to fail
set_tests_properties(example PROPERTIES  WILL_FAIL true)

# ..regular expressions can be passed to check the result of the test
# PASS_REGULAR_EXPRESSION / FAIL_REGULAR_EXPRESSION
