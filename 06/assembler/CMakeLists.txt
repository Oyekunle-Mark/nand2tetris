cmake_minimum_required(VERSION 3.17)
project(assembler)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall")

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(student ${SOURCES})
