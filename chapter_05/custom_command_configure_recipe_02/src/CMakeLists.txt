# The minimum required CMake Version
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# Set the project name and the compile language
project(recipe_02 LANGUAGES NONE)

# Search for the Python interpreter
find_package(PythonInterp REQUIRED)

# This is set as variable to prepare
# for abstraction using loops or functions
set(_module_name "cffi")

# Run a Pyhon program with execute_process
execute_process(
   COMMAND
      ${PYTHON_EXECUTABLE} "-c" "import ${_module_name}; print(${_module_name}.__version__)"
      OUTPUT_VARIABLE _stdout
      ERROR_VARIABLE _stderr
      OUTPUT_STRIP_TRAILING_WHITESPACE
      ERROR_STRIP_TRAILING_WHITESPACE
)

# Print results
if (_stderr MATCHES "ModuleNotFoundError")
   message(STATUS "Module ${_module_name} not found")
else()
   message(STATUS "Found module ${_module_name} v${_stdout}")
endif()

