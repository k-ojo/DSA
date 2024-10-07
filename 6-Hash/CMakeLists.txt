cmake_minimum_required(VERSION 3.10)

project(STACK VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall")

file(GLOB SOURCES "src/*.c" "*.c" "../4-ds_trees/src/*.c" "../3-ds_queue/queue.c")

add_executable(app ${SOURCES})
