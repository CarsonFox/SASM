#include <iostream>
#include <random>

std::random_device os_randomness;
std::default_random_engine rng(os_randomness());
std::bernoulli_distribution fifty_fifty(0.5);
std::uniform_int_distribution<> addrDist(0, 128 - 1);

std::string literalOrAddress() {
    return std::string(fifty_fifty(rng) ? "&" : "") + std::to_string(addrDist(rng));
}

std::string address() {
    return std::string("&") + std::to_string(addrDist(rng));
}

std::string zeroOrOne() {
    return fifty_fifty(rng) ? "0" : "1";
}

std::string lineNo(int n) {
    static std::uniform_int_distribution<> lineDist(0, n - 1);
    return std::to_string(lineDist(rng));
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage: ./Random n" << std::endl;
        return 1;
    }

    const int n = std::atoi(argv[1]);

    const std::vector<std::string> instructions = {
            "SET", "ADD", "OUT",
    };

    std::uniform_int_distribution<> insDist(0, instructions.size() - 1);

    for (int i = 0; i < n; i++) {
        const int ins = insDist(rng);
        if (ins < 2) {
            std::cout << instructions[ins] << ' ' << address() << ' ' << literalOrAddress() << std::endl;
//        } else if (ins == 3) {
//            std::cout << "JMP " << literalOrAddress() << ' ' << lineNo(n) << std::endl;
        } else {
            std::cout << "OUT " << literalOrAddress() << ' ' << zeroOrOne() << std::endl;
        }
    }
    std::cout << "EXT" << std::endl;
}