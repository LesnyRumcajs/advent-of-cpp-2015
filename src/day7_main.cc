#include "day7.h"

#include <iostream>
#include <fstream>
#include <sstream>

int main(void) {
    std::ifstream input_file("../../inputs/day7");
    std::stringstream buffer;
    buffer << input_file.rdbuf();

    std::cout << "Day 7, part 1: " << day7::calculateSignal(buffer.str(), "a") <<  '\n';
    std::cout << "Day 7, part 2: " << day7::calculateOverridenSignal(buffer.str(), "a", "b") << '\n';
}