cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(recipe-01 LANGUAGES NONE)
# Go and find the Python Interpreter
find_package(PythonInterp REQUIRED)
# Execute a Python command
execute_process(
    COMMAND ${PYTHON_EXECUTABLE} "-c" "print('Hello World!')"
    RESULT_VARIABLE _status
    OUTPUT_VARIABLE _hello_world
    #ERROR_QUIET
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
# Print the return value and the output from the Python command
message(STATUS "RESULT_VARIABLE is: ${_status}")
message(STATUS "OUTPUT_VARIABLE is: ${_hello_world}")