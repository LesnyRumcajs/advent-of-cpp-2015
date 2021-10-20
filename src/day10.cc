#include "day10.h"

#include <iostream>

int main() {
    static constexpr auto input = "1113122113";
    const auto result1 = day10::playLookAndSay(input, 40);
    const auto result2 = day10::playLookAndSay(result1, 10);
    std::cout << "Day 10, part 1: " << result1.length() << '\n';
    std::cout << "Day 10, part 2: " << result2.length() << '\n';
}
