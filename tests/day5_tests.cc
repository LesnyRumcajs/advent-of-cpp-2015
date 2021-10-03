#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../src/day5.h"
TEST_CASE("Day5::part1", "[isNice]") {
    REQUIRE(day5::isNice("ugknbfddgicrmopn"));
    REQUIRE(day5::isNice("aaa"));
    REQUIRE(!day5::isNice("jchzalrnumimnmhp"));
    REQUIRE(!day5::isNice("haegwjzuvuyypxyu"));
    REQUIRE(!day5::isNice("dvszwmarrgswjxmb"));
    REQUIRE(!day5::isNice("mxzgwhaqobyvckcm"));
}

TEST_CASE("Day5::part2", "[betterNice]") {
    REQUIRE(day5::isBetterNice("qjhvhtzxzqqjkmpb"));
    REQUIRE(day5::isBetterNice("xxyxx"));
    REQUIRE(day5::isBetterNice("xyxy"));
    REQUIRE(!day5::isBetterNice("efe"));
    REQUIRE(!day5::isBetterNice("aaa"));
    REQUIRE(!day5::isBetterNice("punnn"));
    REQUIRE(day5::isBetterNice("aaabbbcccicdddd"));
    REQUIRE(!day5::isBetterNice("uurcxstgmygtbstg"));
    REQUIRE(!day5::isBetterNice("ieodomkazucvgmuy"));
}

