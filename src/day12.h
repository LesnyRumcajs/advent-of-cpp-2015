#pragma once

#include <string_view>
#include <regex>
#include <numeric>

namespace day12 {
    [[nodiscard]] auto sumAllNumbers(const std::string &input) -> int32_t {
        static const auto regex = std::regex(R"((-?\d+))");
        return std::accumulate(std::sregex_iterator(input.begin(), input.end(), regex), std::sregex_iterator(), 0,
                               [](auto sum, const auto &num) {
                                   return sum + std::stoi(num.str());
                               });
    }
}
