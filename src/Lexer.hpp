#pragma once

#include <iostream>
#include "tokens.hpp"

class Lexer {
public://TODO isolate
    std::istream &input;
    int num = 0;
    int indirection = 0;

public:
    Lexer(): input(std::cin) {}
    Token next();
    void address();
    bool eof() const;
};