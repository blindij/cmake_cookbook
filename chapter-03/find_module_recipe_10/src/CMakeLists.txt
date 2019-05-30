# The required minimum version of CMake
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# Set project name and language
project(find_module_recipe_10 LANGUAGES C)

# Settings
set(CMAKE_CXX_STANDARD 99)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Append the current source directory to the list of search paths
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
# Append "/usr/local"
# list(APPEND CMAKE_MODULE_PATH "/usr/local")

# Go searching for ZeroMQ
find_package(ZeroMQ REQUIRED)

# Add executable
add_executable(hwserver hwserver.c)
target_include_directories(hwserver
   PRIVATE
      ${ZeroMQ_INCLUDE_DIRS}
)
target_link_libraries(hwserver
   PRIVATE
      ${ZeroMQ_LIBRARIES}
)

add_executable(hwclient hwclient.c)
target_include_directories(hwclient
   PRIVATE
      ${ZeroMQ_INCLUDE_DIRS}
)
target_link_libraries(hwclient
   PRIVATE
      ${ZeroMQ_LIBRARIES}
)

