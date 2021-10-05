# frozen_string_literal: true

require 'fileutils'

if ARGV.length != 1
  puts 'Usage: ruby scaffold_day.rb <DAY_NUMBER>'
  exit 1
end

day_nr = ARGV[0]

puts 'Creating scaffold C++ files...'
File.open("src/day#{day_nr}.h", 'w') do |f|
  f << <<~HEREDOC
  #pragma once

  namespace day#{day_nr} {
  }
  HEREDOC
end

File.open("src/day#{day_nr}.cc", 'w') do |f|
  f << <<~HEREDOC
  #include "day#{day_nr}.h"

  #include <iostream>
  #include <fstream>
  #include <sstream>

  int main(void) {
    std::ifstream input_file("../../inputs/day#{day_nr}");
    std::stringstream buffer;
    buffer << input_file.rdbuf();

    std::cout << "Day #{day_nr}, part 1: " << '\\n';
    std::cout << "Day #{day_nr}, part 2: " << '\\n';
  }
  HEREDOC
end

File.open("tests/day#{day_nr}_tests.cc", 'w') do |f|
  f << <<~HEREDOC
  #define CATCH_CONFIG_MAIN

  #include <catch2/catch.hpp>
  #include "../src/day#{day_nr}.h"

  TEST_CASE("Day#{day_nr}::part1", "[]") {
    REQUIRE(1 == 1);
  }

  TEST_CASE("Day#{day_nr}::part1", "[]") {
    REQUIRE(2 == 2);
  }
  HEREDOC
end

puts 'Adding entry in CMakeLists...'
File.open('src/CMakeLists.txt', 'a') do |f|
  f << <<~HEREDOC

  add_executable(
          day#{day_nr}
          day#{day_nr}.cc
          day#{day_nr}.h)
  conan_target_link_libraries(day#{day_nr})
  HEREDOC
end

File.open('tests/CMakeLists.txt', 'a') do |f|
  f << <<~HEREDOC

  add_executable(
          day#{day_nr}_tests
          day#{day_nr}_tests.cc
  )
  conan_target_link_libraries(day#{day_nr}_tests)
  add_test(
          NAME day#{day_nr}_tests
          COMMAND day#{day_nr}_tests)

  HEREDOC
end

puts 'Adding files to git...'
`git add src/day#{day_nr}.h`
`git add src/day#{day_nr}.cc`
`git add tests/day#{day_nr}_tests.cc`

puts 'Done! Happy Advent!'