#pragma once

#include <variant>

#include "../tokens.hpp"
#include "BinaryInstruction.hpp"

class Instruction {
    Token type;
    std::variant<std::monostate, Set, Add, Jump, Out> instruction;
};