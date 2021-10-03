#include "day4.h"

#include <iostream>

int main(void) {
    static constexpr auto input = "yzbqklnj";
    std::cout << "Day 4, part 1: " << day4::mineAdventCoin(input, false) << '\n';
    std::cout << "Day 4, part 2: " << day4::mineAdventCoin(input, true) << '\n';
}
