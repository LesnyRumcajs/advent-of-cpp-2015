#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "../src/day11.h"

TEST_CASE("Day11::part1&2", "[]") {
    REQUIRE("abcdffaa" == day11::createNextSecurePassword("abcdefgh"));
    REQUIRE("ghjaabcc" == day11::createNextSecurePassword("ghijklmn"));
}