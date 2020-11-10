#include "Interpreter.hpp"

Interpreter::Interpreter() {
    memory.fill(0);

    while (!parser.eof()) {
        instructions.push_back(parser.parse());
    }
    //Add an Exit instruction at the end
    instructions.emplace_back();
}

void Interpreter::execute() {
    Instruction current;
    for (;;) {
        current = instructions[pc++];
        switch (current.type) {
            case SET:
                set(current);
                break;
            case ADD:
                add(current);
                break;
            case JMP:
                jump(current);
                break;
            case OUT:
                out(current);
                break;
            case EXT:
                return;
            default:
                std::cerr << "Unsupported opcode" << std::endl;
                std::exit(EXIT_FAILURE);
        }
    }
}

void Interpreter::set(Instruction &ins) {
    auto setIns = std::get<Set>(ins.instruction);
    memory[setIns.A.resolve(memory)] = setIns.B.getValue(memory);
}

void Interpreter::add(Instruction &ins) {
    auto addIns = std::get<Add>(ins.instruction);
    memory[addIns.A.resolve(memory)] += addIns.B.getValue(memory);
}

void Interpreter::jump(Instruction &ins) {
    auto jumpIns = std::get<Jump>(ins.instruction);
    if (jumpIns.A.getValue(memory) == 0) {
        pc = jumpIns.B.getValue(memory);
    }
}

void Interpreter::out(Instruction &ins) {
    auto outIns = std::get<Out>(ins.instruction);
    int Aval = outIns.A.getValue(memory);

    if (outIns.B.getValue(memory) == 0) {
        std::cout << static_cast<char>(Aval);
    } else {
        std::cout << Aval;
    }
}
