#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "../src/day3.h"

TEST_CASE("Day3::part1", "[countVisitedHouses]") {
    REQUIRE(2 == day3::countVisitedHouses(">"));
    REQUIRE(4 == day3::countVisitedHouses("^>v<"));
    REQUIRE(2 == day3::countVisitedHouses("^v^v^v^v^v"));
}

TEST_CASE("Day3::part2", "[countVisitedHousesWithRoboSanta]") {
    REQUIRE(3 == day3::countVisitedHousesWithRoboSanta("^v"));
    REQUIRE(3 == day3::countVisitedHousesWithRoboSanta("^>v<"));
    REQUIRE(11 == day3::countVisitedHousesWithRoboSanta("^v^v^v^v^v"));
}
