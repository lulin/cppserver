cmake_minimum_required(VERSION 3.2)
project(cppserver)
message(var=${var1})
# find libcppcms
find_path(CPPCMS_INCLUDE_DIR cppcms/application.h)
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

