# set minimum cmake version
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# project name and language
project(recipe-03 LANGUAGES CXX)

# settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# finding the interpreter, headers and libraries
find_package(PythonInterp REQUIRED)
find_package(PythonLibs
    ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}
    EXACT
    REQUIRED
 )

 # Python script used for probing modules
 execute_process(
     COMMAND
        ${PYTHON_EXECUTABLE} "-c" "import re,numpy; print(re.compile('/__init__.py.*').sub('',numpy.__file__))"
     RESULT_VARIABLE _numpy_status 
     OUTPUT_VARIABLE _numpy_location
     ERROR_QUIET
     OUTPUT_STRIP_TRAILING_WHITESPACE
 )
 # Create a numpy location variable
 if (NOT _numpy_status)
    set(NumPy ${_numpy_location} CACHE STRING "Location of Numpy")
endif()

# Check the version of numpy
execute_process(
    COMMAND
        ${PYTHON_EXECUTABLE} "-c" "import numpy;print(numpy.__version__)"
    OUTPUT_VARIABLE _numpy_version
    ERROR_QUIET
)

# Set NumPy_FOUND Variable
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Numpy
    FOUND_VAR Numpy_FOUND
    REQUIRED_VARS NumPy
    VERSION_VAR _numpy_version
)
# compile the executable
add_executable(pure_embedding "")

# link to the Python libraries
target_sources(pure_embedding
    PRIVATE
        Py${PYTHON_VERSION_MAJOR}_pure_embedding.cpp
)

target_include_directories(pure_embedding
    PRIVATE
        ${PYTHON_INCLUDE_DIRS}    
)

target_link_libraries(pure_embedding
    PRIVATE
        ${PYTHON_LIBRARIES}
)

# make sure use_numpy.py is available in the build directory
add_custom_command(
    OUTPUT
      ${CMAKE_CURRENT_BINARY_DIR}/use_numpy.py
    COMMAND
      ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/use_numpy.py
                                            ${CMAKE_CURRENT_BINARY_DIR}/use_numpy.py
    DEPENDS
      ${CMAKE_CURRENT_SOURCE_DIR}/use_numpy.py
)
# make sure building pure_embedding triggers above custom command
target_sources(pure_embedding
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/use_numpy.py
)
