# minimum required CMake verison
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# project name and languages
project(recipe_05 LANGUAGES Fortran)

# Search for the Python interpreter
find_package(PythonInterp REQUIRED)

# Select "Release" build type
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# define executable target
add_executable(example "")
target_sources(example
    PRIVATE
        example.f90
)

# define a custom command to print the link line
add_custom_command(
    TARGET
        example
    PRE_LINK
    COMMAND
        ${PYTHON_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/echo_file.py
            ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/example.dir/link.txt
    COMMENT
        "link line:"
    VERBATIM
)

# define a custom command to print the static size
add_custom_command(
    TARGET
        example
    POST_BUILD
    COMMAND
        ${PYTHON_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/static_size.py
            $<TARGET_FILE:example>
    COMMENT
        "static size of executable:"
    VERBATIM
)
