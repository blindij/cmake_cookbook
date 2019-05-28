# Minimum required CMake version
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# Project name
project(Eigen-recipe_07 LANGUAGES CXX)

# Settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Go searching for OpenMP
find_package(OpenMP REQUIRED)

# Go searching for Eigen
find_package(Eigen3 3.3 REQUIRED CONFIG)

# Print out status message about Eigen
if (TARGET Eigen3::Eigen)
   message(STATUS "Eigen3 v${EIGEN3_VERSION_STRING} found in ${EIGEN_INCLUDE_DIR}")
endif()

# Add executable
add_executable(linear_algebra linear_algebra.cpp)

# Go searching for BLAS
find_package(BLAS)

# if BLAS is found, set corresponding compile definitions and link libraries
if(BLAS_FOUND)
   message(STATUS "Eigen will use some subroutines from BLAS.")
   message(STATUS "See:
   http://eigen.tuxfamily.org/dox-devel/TopicusUsingBlasLapack.html")
   target_compile_definitions(linear_algebra
      PRIVATE
         EIGEN_USE_BLAS
   )
   target_link_libraries(linear_algebra
      PUBLIC
         ${BLAS_LIBRARIES}
   )
else()
   message(STATUS "BLAS not found. Using Eigen own functions")
endif()

# Link to the imported Eigen3::Eigen and OpenMP::OpenMP_CXX
target_link_libraries(linear_algebra
   PUBLIC
      Eigen3::Eigen
      OpenMP::OpenMP_CXX
)

