cmake_minimum_required(VERSION 3.2)
project(cppserver)

set(with_cppcms "" CACHE STRING "path where libcppcms is located")
set(with_cppcms_headers ${with_cppcms} CACHE STRING "cppcms headers path")
set(with_cppcms_libs ${with_cppcms} CACHE STRING "cppcms libs path")

# find libcppcms
find_path(CPPCMS_INCLUDE_DIR cppcms/application.h
    $<$<STREQUAL:"${with_cppcms}","">:NO_DEFAULT_PATH>)
find_library(CPPCMS_LIB cppcms)
if(NOT CPPCMS_INCLUDE_DIR OR NOT CPPCMS_LIB)
    message(FATAL_ERROR "-- libcppcms -- required
        ${CPPCMS_INCLUDE_DIR}
        ${CPPCMS_LIB}")
endif()

# cppserver
#add_executable(cppserver)
#target_link_libraries(cppserver ${CPPCMS_LIB})
# source
add_subdirectory(src)
# page templates
#add_subdirectory(tmpl)

