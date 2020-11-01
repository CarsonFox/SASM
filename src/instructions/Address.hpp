#pragma once

class Address {
    int indirection, num;

public:
    Address() = default;
    Address(int i, int n): indirection(i), num(n) {}
};
