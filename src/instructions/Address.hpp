#pragma once

#include <array>

class Address {
    int indirection, num;

public:
    Address() = default;
    Address(int i, int n): indirection(i), num(n) {}
    int resolve(std::array<int, 128> &memory) const;
    int getValue(std::array<int, 128> &memory) const;
};
