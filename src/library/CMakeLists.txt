file(GLOB_RECURSE SRC *.h *.hpp *.cpp)

add_library(matrix_lib ${SRC})

target_include_directories(matrix_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
