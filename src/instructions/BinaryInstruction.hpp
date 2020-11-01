#pragma once

#include "Address.hpp"

class Lexer;

struct BinaryInstruction {
    Address A, B;

    explicit BinaryInstruction(Lexer &lexer);
};

class Set: public BinaryInstruction {
    using BinaryInstruction::BinaryInstruction;
};

class Add: public BinaryInstruction {
    using BinaryInstruction::BinaryInstruction;
};

class Jump: public BinaryInstruction {
    using BinaryInstruction::BinaryInstruction;
};

class Out: public BinaryInstruction {
    using BinaryInstruction::BinaryInstruction;
};