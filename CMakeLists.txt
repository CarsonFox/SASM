cmake_minimum_required(VERSION 3.0)
project(SASM)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")

set(src main.cpp Lexer.cpp Lexer.hpp tokens.hpp)

add_executable(SASM ${src})