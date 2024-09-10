cmake_minimum_required(VERSION 3.10)

project(0-ds_lnklst VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

file(GLOB SOURCES "*.c")

add_executable(app ${SOURCES})
