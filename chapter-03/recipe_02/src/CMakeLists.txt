cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(recipe-02 LANGUAGES C)

# enforce the use of C99
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

# find the Python interpreter
find_package(PythonInterp REQUIRED)

# find the Python header and library
find_package(PythonLibs ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR} EXACT REQUIRED)
message(STATUS "Python include subdirectory is: ${PYTHON_INCLUDE_DIRS}")

# add executable target
add_executable(hello_embedded_python hello_embedded_python.c)

# include the Python include subdirectory
target_include_directories(hello_embedded_python PRIVATE
    ${PYTHON_INCLUDE_DIRS}
)

# link executable with the Python library
target_link_libraries(hello_embedded_python
    ${PYTHON_LIBRARIES}
)

