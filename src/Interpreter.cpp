#include "Interpreter.hpp"

#include <array>

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

    constexpr void* labels[] = {
            [SET] = &&set_label,
            [ADD] = &&add_label,
            [JMP] = &&jump_label,
            [OUT] = &&out_label,
            [EXT] = &&exit_label,
    };

    auto const next = [&] {
        current = instructions[pc++];
        return labels[current.type];
    };

    goto* next();

    set_label:
        set(current);
        goto* next();
    add_label:
        add(current);
        goto* next();
    jump_label:
        jump(current);
        goto* next();
    out_label:
        out(current);
        goto* next();
    exit_label:
        return;
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
