# set minimum cmake version
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# set project name and language
project(recipe_10 LANGUAGES NONE)

# detect python
find_package(PythonInterp REQUIRED)

# define tests
enable_testing()

add_test(NAME setup COMMAND 
    ${PYTHON_EXECUTABLE}
    ${CMAKE_CURRENT_SOURCE_DIR}/test/setup.py
)
set_tests_properties(setup PROPERTIES FIXTURES_SETUP my_fixture)

add_test(NAME feature-a COMMAND
    ${PYTHON_EXECUTABLE}
    ${CMAKE_CURRENT_SOURCE_DIR}/test/feature-a.py
)
add_test(NAME feature-b COMMAND
    ${PYTHON_EXECUTABLE}
    ${CMAKE_CURRENT_SOURCE_DIR}/test/feature-b.py
)
set_tests_properties(
    feature-a
    feature-b
    PROPERTIES
        FIXTURES_REQUIRED my_fixture
)

add_test(
    NAME cleanup
    COMMAND ${PYTHON_EXECUTABLE}
    ${CMAKE_CURRENT_SOURCE_DIR}/test/cleanup.py
)
set_tests_properties(
    cleanup
    PROPERTIES
        FIXTURES_CLEANUP my_fixture
)
