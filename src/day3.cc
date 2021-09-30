#include "day3.h"

#include <iostream>
#include <fstream>
#include <sstream>

int main(void) {
    std::ifstream input_file("../../inputs/day3");
    std::stringstream buffer;
    buffer << input_file.rdbuf();

    std::cout << "Day 3, part 1: " <<  day3::countVisitedHouses(buffer.str()) << '\n';
    std::cout << "Day 3, part 2: " <<  day3::countVisitedHousesWithRoboSanta(buffer.str()) << '\n';
}
