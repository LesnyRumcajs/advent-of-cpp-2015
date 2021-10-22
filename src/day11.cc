#include "day11.h"

#include <iostream>

int main() {
    auto nextPassword = day11::createNextSecurePassword(("hxbxwxba"));
    std::cout << "Day 11, part 1: " << nextPassword << '\n';
    nextPassword = day11::createNextSecurePassword(nextPassword);
    std::cout << "Day 11, part 2: " << nextPassword << '\n';
}
