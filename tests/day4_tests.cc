#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../src/day4.h"
TEST_CASE("Day4::part1", "[mineAdventCoin]") {
    REQUIRE(609043 == day4::mineAdventCoin("abcdef", false));
    REQUIRE(1048970 == day4::mineAdventCoin("pqrstuv", false));
}

