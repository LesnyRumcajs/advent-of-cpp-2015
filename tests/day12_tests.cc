#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "../src/day12.h"

TEST_CASE("Day12::part1", "[]") {
    REQUIRE(6 == day12::sumAllNumbers("{\"a\":2,\"b\":4}"));
    REQUIRE(3 == day12::sumAllNumbers("{\"a\":{\"b\":4},\"c\":-1}"));
}