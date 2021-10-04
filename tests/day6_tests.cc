#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "../src/day6.h"

TEST_CASE("Day6::part1", "[countLitLights]") {
    REQUIRE(1'000'000 == day6::countLitLights("turn on 0,0 through 999,999"));
    REQUIRE(1'000 == day6::countLitLights("toggle 0,0 through 999,0"));
    REQUIRE(1'000'000 - 4 == day6::countLitLights("turn on 0,0 through 999,999\nturn off 499,499 through 500,500"));
}

TEST_CASE("Day5::part2", "[countLitLightsModern]") {
    REQUIRE(1'000'000 == day6::countLitLightsModern("turn on 0,0 through 999,999"));
    REQUIRE(1 == day6::countLitLightsModern("turn on 0,0 through 0,0"));
    REQUIRE(2'000'000 == day6::countLitLightsModern("toggle 0,0 through 999,999"));
}

