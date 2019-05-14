cmake_minimum_required(VERSION 3.8)                                                                                                                  
set(CMAKE_CXX_STANDARD 11)
project(p32)

find_package(MPI REQUIRED)

include_directories(${MPI_INCLUDE_PATH})
set (SOURCE_FILES
	src/main.cc
	src/complex.cc
	src/complex.h
	src/input_image.cc
	src/input_image.h
)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${MPI_LIBRARIES})