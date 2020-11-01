#include "BinaryInstruction.hpp"
#include "../Lexer.hpp"

BinaryInstruction::BinaryInstruction(Lexer &lexer) {
    lexer.next();
    A = { lexer.indirection, lexer.num };

    lexer.next();
    B = { lexer.indirection, lexer.num };
}
