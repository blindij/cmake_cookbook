# version and mixed languages
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(recipe_01 LANGUAGES Fortran C)

# obtain username from environment
execute_process(
   COMMAND
      whoami
   TIMEOUT
      1
   OUTPUT_VARIABLE
      _user_name
   OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Query system information
cmake_host_system_information(RESULT _host_name QUERY HOSTNAME)
cmake_host_system_information(RESULT _fqdn QUERY FQDN)

# processor information
cmake_host_system_information(RESULT _processor_description QUERY
PROCESSOR_DESCRIPTION)

# os information
cmake_host_system_information(RESULT _os_name QUERY OS_NAME)
cmake_host_system_information(RESULT _os_release QUERY OS_RELEASE)
cmake_host_system_information(RESULT _os_version QUERY OS_VERSION)
cmake_host_system_information(RESULT _os_platform QUERY OS_PLATFORM)

# timestamp
string(TIMESTAMP _configuration_time "%Y-%m-%d %H:%M:%S [UTC]" UTC)

# configure the template file print_info_.c.in
configure_file(src/print_info.c.in print_info.c @ONLY)

# executable
add_executable(example "")
target_sources(example
   PRIVATE
      src/example.f90
      ${CMAKE_CURRENT_BINARY_DIR}/print_info.c
)

