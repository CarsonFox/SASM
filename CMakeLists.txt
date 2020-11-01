cmake_minimum_required(VERSION 3.0)
project(SASM)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")

set(src src/main.cpp src/Lexer.cpp src/Lexer.hpp src/tokens.hpp src/parse.cpp src/parse.hpp)

add_executable(SASM ${src})