#include "day6.h"

#include <iostream>
#include <fstream>
#include <sstream>

int main(void) {
    std::ifstream input_file("../../inputs/day6");
    std::stringstream buffer;
    buffer << input_file.rdbuf();

//    std::cout << "Day 6, part 1: " << day6::countNice(buffer.str()) << '\n';
//    std::cout << "Day 6, part 2: " << day6::countBetterNice(buffer.str()) << '\n';
}
