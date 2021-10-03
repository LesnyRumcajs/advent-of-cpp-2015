#include "day5.h"

#include <iostream>
#include <fstream>
#include <sstream>

int main(void) {
    std::ifstream input_file("../../inputs/day5");
    std::stringstream buffer;
    buffer << input_file.rdbuf();

    std::cout << "Day 5, part 1: " <<  day5::countNice(buffer.str()) << '\n';
    std::cout << "Day 5, part 2: " <<  day5::countBetterNice(buffer.str()) << '\n';
}
