cmake_minimum_required(VERSION 3.12)


set(CMAKE_C_STANDARD 11)


project(ring_buffer)
add_executable( tests tests.c ring_buffer.c )
add_library(ring_buffer ring_buffer.c ring_buffer.h)

target_include_directories(ring_buffer PRIVATE ${CMAKE_CURRENT_LIST_DIR})

