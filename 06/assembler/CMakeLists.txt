cmake_minimum_required(VERSION 3.17)
project(assembler)

set(CMAKE_CXX_STANDARD 20)

add_executable(assembler main.cpp code.cpp code.h types.h parser.cpp parser.h)