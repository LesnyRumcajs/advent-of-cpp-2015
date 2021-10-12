#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "../src/day8.h"

TEST_CASE("Day8::part1", "[]") {
    auto input = "\"\"\n"
                 "\"abc\"\n"
                 "\"aaa\\\"aaa\"\n"
                 "\"\\x27\"\n";
    REQUIRE(12 == day8::countCharacters(input));

    input = R"("nnx\\krnrfomdnt\x2flbl\xd2xpo\"cp\"k")";
    REQUIRE(11 == day8::countCharacters(input));
}

TEST_CASE("Day8::part2", "[]") {
    REQUIRE(2 == 2);
}
