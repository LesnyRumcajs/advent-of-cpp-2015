#include "day2.h"

#include <iostream>
#include <fstream>

int main(void) {
    std::ifstream input_file("../../inputs/day2");
    std::stringstream buffer;
    buffer << input_file.rdbuf();

    std::cout << "Day 2, part 1: " <<  day2::calculatePackagePaper(buffer.str()) << '\n';
    std::cout << "Day 2, part 2: " <<  day2::calculateRibbon(buffer.str()) << '\n';
}