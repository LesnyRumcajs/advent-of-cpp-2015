#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "../src/day7.h"

TEST_CASE("Day7::part1", "[]") {
    auto input = "123 -> x\n"
                 "456 -> y\n"
                 "x AND y -> d\n"
                 "x OR y -> e\n"
                 "x LSHIFT 2 -> f\n"
                 "y RSHIFT 2 -> g\n"
                 "NOT x -> h\n"
                 "NOT y -> i";
    REQUIRE(72 == day7::calculateSignal(input, "d"));
    REQUIRE(507 == day7::calculateSignal(input, "e"));
    REQUIRE(492 == day7::calculateSignal(input, "f"));
    REQUIRE(114 == day7::calculateSignal(input, "g"));
    REQUIRE(65412 == day7::calculateSignal(input, "h"));
    REQUIRE(65079 == day7::calculateSignal(input, "i"));
    REQUIRE(123 == day7::calculateSignal(input, "x"));
    REQUIRE(456 == day7::calculateSignal(input, "y"));
}