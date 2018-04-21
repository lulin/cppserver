add_executable(cppserver $<TARGET_OBJECTS:objlib>)
target_link_libraries(cppserver cppcms)
target_include_directories(cppserver PUBLIC
    ${COMMON_INCLUDE_PATH}
    )

set(COMMON_INCLUDE_PATH
    ../include;)
file(GLOB cpp_sources *.cpp)
add_library(objlib OBJECT ${cpp_sources})
