cmake_minimum_required(VERSION 3.0)
project(SASM)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3")

set(src src/main.cpp
        src/Lexer.cpp src/Lexer.hpp
        src/tokens.hpp
        src/instructions/Instruction.cpp src/instructions/Instruction.hpp
        src/instructions/Address.cpp src/instructions/Address.hpp
        src/instructions/BinaryInstruction.cpp src/instructions/BinaryInstruction.hpp
        src/Parser.cpp src/Parser.hpp
        src/Interpreter.cpp src/Interpreter.hpp)

add_executable(SASM ${src})
add_executable(Random randomCode.cpp)