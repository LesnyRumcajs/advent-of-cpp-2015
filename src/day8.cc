#include "day8.h"

#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream input_file("../../inputs/day8");
    std::stringstream buffer;
    buffer << input_file.rdbuf();

    std::cout << "Day 8, part 1: " << day8::countCharacters(buffer.str()) << '\n';
    std::cout << "Day 8, part 2: " << '\n';
}
