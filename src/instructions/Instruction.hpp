#pragma once

#include <variant>

#include "../tokens.hpp"
#include "BinaryInstruction.hpp"

struct Instruction {
    Token type;
    std::variant<std::monostate, Set, Add, Jump, Out> instruction;

    Instruction(): type(EXT) {}
    explicit Instruction(Set setIns): type(SET), instruction(setIns)    {}
    explicit Instruction(Add addIns): type(ADD), instruction(addIns)    {}
    explicit Instruction(Jump jumpIns): type(JMP), instruction(jumpIns) {}
    explicit Instruction(Out outIns): type(OUT), instruction(outIns)    {}
};