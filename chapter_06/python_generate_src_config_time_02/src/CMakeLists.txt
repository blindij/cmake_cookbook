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
#configure_file(src/print_info.c.in print_info.c @ONLY)
set(_config_script
"
from pathlib import Path
source_dir = Path('${CMAKE_CURRENT_SOURCE_DIR}')
binary_dir = Path('${CMAKE_CURRENT_BINARY_DIR}')
input_file = source_dir / 'print_info.c.in'
output_file = binary_dir / 'print_info.c'

import sys
sys.path.insert(0, str(source_dir))

from configurator import configure_file
vars_dict = {
    '_user_name':              '${_user_name}',
    '_host_name':              '${_host_name}',
    '_fqdn':                   '${_fqdn}',
    '_processor_name':         '${_processor_name}',
    '_processor_description':  '${_processor_description}',
    '_os_name':                '${_os_name}',
    '_os_release':             '${_os_release}',
    '_os_version':             '${_os_version}',
    '_os_platform':            '${_os_platform}',
    '_configuration_time':     '${_configuration_time}',
    'CMAKE_VERSION':           '${CMAKE_VERSION}',
    'CMAKE_GENERATOR':         '${CMAKE_GENERATOR}',
    'CMAKE_Fortran_COMPILER':  '${CMAKE_Fortran_COMPILER}',
    'CMAKE_C_COMPILER':        '${CMAKE_C_COMPILER}',
}
configure_file(input_file, output_file, vars_dict)
")

# search for python
find_package(PythonInterp QUIET REQUIRED)

# run _config_script
execute_process(
    COMMAND
        ${PYTHON_EXECUTABLE} "-c" ${_config_script}
)

# executable
add_executable(example "")
target_sources(example
   PRIVATE
      example.f90
      ${CMAKE_CURRENT_BINARY_DIR}/print_info.c
)

