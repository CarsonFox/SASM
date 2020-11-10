#include "Parser.hpp"

#include "instructions/BinaryInstruction.hpp"

Instruction Parser::parse() {
    switch (lexer.next()) {
        case SET:
            return Instruction(Set(lexer));
        case ADD:
            return Instruction(Add(lexer));
        case JMP:
            return Instruction(Jump(lexer));
        case OUT:
            return Instruction(Out(lexer));
        case EXT:
            return Instruction();

        default:
            std::cerr << "Syntax error" << std::endl;
            std::exit(EXIT_FAILURE);
    }
}

bool Parser::eof() const {
    return lexer.eof();
}
