#pragma once

#include <numeric>
#include <cstring>

namespace day1 {
[[nodiscard]] constexpr auto findTargetFloor(const auto* input) -> int {
    return std::accumulate(input, input + std::strlen(input), 0, [&](auto sum, auto c) {
        return sum + (c == '(' ? 1 : -1);
    });
}

[[nodiscard]] constexpr auto findFirstBasementFloor(const auto* input) -> int {
    return std::find_if(input, input + std::strlen(input), [&, floor = 0](auto c) mutable {
        floor += c == '(' ? 1 : - 1;
        return floor == -1;
    }) - input + 1;
}
}