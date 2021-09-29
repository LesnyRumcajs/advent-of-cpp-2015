#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../src/day2.h"
TEST_CASE("Day2::part1", "[calculatePackagePaper]") {
    REQUIRE(58 == day2::calculatePackagePaper("2x3x4"));
    REQUIRE(43 == day2::calculatePackagePaper("1x1x10"));
}

TEST_CASE("Day2::part2", "[calculateRibbon]") {
    REQUIRE(34 == day2::calculateRibbon("2x3x4"));
    REQUIRE(14 == day2::calculateRibbon("1x1x10"));
}
