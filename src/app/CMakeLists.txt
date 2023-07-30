file(GLOB_RECURSE SRC *.h *.hpp *.cpp)

add_executable(matrix ${SRC})

target_link_libraries(matrix PRIVATE
	matrix_lib
)
