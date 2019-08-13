# cmake minimum 
cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(recipe_02 LANGUAGES NONE)

# subdirectory
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# include the `colors.cmake`
include(colors)
define_colors()

# print messages in different colors:
message(STATUS "This is a normal message")
message(STATUS "${Red} is red${ColourReset}")
message(STATUS "${BoldRed}This is a bold red${ColourReset}")
message(STATUS "${Green}This is a green${ColourReset}")
message(STATUS "${BoldMagenta}This is a bold${ColourReset}")
