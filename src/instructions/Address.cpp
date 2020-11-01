#include "Address.hpp"

//Assume this is a memory address, get its value
int Address::resolve(std::array<int, 128> &memory) const {
    int p = num;
    for (int i = 1; i < indirection; i++)
        p = memory[p];
    return p;
}

//If this is a literal, return it. If an address, look it up in memory
int Address::getValue(std::array<int, 128> &memory) const {
    if (indirection) {
        return memory[resolve(memory)];
    } else {
        return num;
    }
}
