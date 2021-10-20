#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "../src/day10.h"

TEST_CASE("Day10::part1&2", "[]") {
    REQUIRE("11" == day10::playLookAndSay("1", 1));
    REQUIRE("21" == day10::playLookAndSay("1", 2));
    REQUIRE("1211" == day10::playLookAndSay("1", 3));
    REQUIRE("111221" == day10::playLookAndSay("1", 4));
    REQUIRE("312211" == day10::playLookAndSay("1", 5));
}