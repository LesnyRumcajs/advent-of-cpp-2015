#include "day12.h"

#include <iostream>
#include <fstream>
#include <sstream>

int main() {
  std::ifstream input_file("../../inputs/day12");
  std::stringstream buffer;
  buffer << input_file.rdbuf();

  std::cout << "Day 12, part 1: " << day12::sumAllNumbers(buffer.str()) << '\n';
//  std::cout << "Day 12, part 2: " << '\n';
}
