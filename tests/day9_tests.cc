#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "../src/day9.h"

TEST_CASE("Day9::part1+2", "[]") {
    auto input = "London to Dublin = 464\n"
                 "London to Belfast = 518\n"
                 "Dublin to Belfast = 141";

    const auto[shortest, longest] = day9::calculateMinMaxPath(input);
    REQUIRE(605 == shortest);
    REQUIRE(982 == longest);
}

