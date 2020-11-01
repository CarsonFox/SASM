#pragma once

#include "Lexer.hpp"
#include "instructions/Instruction.hpp"

class Parser {
    Lexer lexer;
public:
    Instruction parse();
};
