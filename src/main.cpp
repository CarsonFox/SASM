#include <iostream>

#include "Lexer.hpp"

int main() {
    Lexer lexer;
    
    for (;;) {
        switch (lexer.next()) {
            case SET:
                std::cout << "SET ";
                break;
            case ADD:
                std::cout << "ADD ";
                break;
            case JMP:
                std::cout << "JMP ";
                break;
            case OUT:
                std::cout << "OUT ";
                break;
            case EXT:
                std::cout << "EXT ";
                break;
            case ADDR:
                for (int i = 0; i < lexer.indirection; i++)
                    std::cout << '&';
            case NUM:
                std::cout << lexer.num << ' ';
                break;
            case END:
                return 0;
        }
    }
}
