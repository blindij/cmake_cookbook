add_library(initial "")

target_sources(initial
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/initial.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/initial.hpp
)

target_include_directories(initial
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)
