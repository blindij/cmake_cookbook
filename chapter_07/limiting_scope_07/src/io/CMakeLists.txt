add_library(io "")

target_sources(io
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/io.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/io.hpp
)

target_include_directories(io
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)
