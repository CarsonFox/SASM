#pragma once

#include <array>
#include <vector>

#include "Parser.hpp"

class Interpreter {
    std::array<int, 128> memory;
    int &pc = memory[0];
    std::vector<Instruction> instructions;
    Parser parser;

    void set(Instruction &ins);
    void add(Instruction &ins);
    void jump(Instruction &ins);
    void out(Instruction &ins);

public:
    Interpreter();
    void execute();
};