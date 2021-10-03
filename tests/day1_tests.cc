#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "../src/day1.h"


TEST_CASE("Day1::part1", "[findTargetFloor]") {
    REQUIRE(0 == day1::findTargetFloor(""));
    REQUIRE(2 == day1::findTargetFloor("()()(("));
}

TEST_CASE("Day1::part2", "[findFirstBasementFloor]") {
    REQUIRE(1 == day1::findFirstBasementFloor(")"));
    REQUIRE(5 == day1::findFirstBasementFloor("(()))"));
}