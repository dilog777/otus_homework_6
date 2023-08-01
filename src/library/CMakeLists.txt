file(GLOB_RECURSE SRC *.h *.hpp *.cpp)

add_library(matrix_lib INTERFACE ${SRC})

target_include_directories(matrix_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
