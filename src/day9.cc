#include "day9.h"

#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream input_file("../../inputs/day9");
    std::stringstream buffer;
    buffer << input_file.rdbuf();

    const auto[min, max] = day9::calculateMinMaxPath((buffer.str()));
    std::cout << "Day 9, part 1: " << min << '\n';
    std::cout << "Day 9, part 2: " << max << '\n';
}
