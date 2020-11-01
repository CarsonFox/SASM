#include "Lexer.hpp"

Token Lexer::next() {
    //Skip whitespace
    input >> std::ws;

    //Reset state
    indirection = num = 0;

    switch (input.peek()) {
        case 'S':
            input.ignore(3);
            return SET;
        case 'A':
            input.ignore(3);
            return ADD;
        case 'J':
            input.ignore(3);
            return JMP;
        case 'O':
            input.ignore(3);
            return OUT;
        case 'E':
            input.ignore(3);
            return EXT;

        case '&':
            address();
            return ADDR;

        case '-':
        case '0'...'9':
            input >> num;
            return Token::NUM;

        default:
            //Implicit exit instruction at the end
            return EXT;
    }
}

void Lexer::address() {
    indirection = 0;
    while (input.peek() == '&') {
        indirection++;
        input.get();
    }
    input >> num;
}

bool Lexer::eof() const {
    return input.eof();
}
