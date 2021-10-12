#pragma once

#include <string_view>
#include <range/v3/view/split.hpp>
#include <range/v3/algorithm/for_each.hpp>

namespace day8 {
    auto countCharacters(std::string_view input) {
        auto stringLiteralsCount = uint32_t{};
        auto charactersInMemory = uint32_t{};

        ranges::for_each(ranges::views::split(input, '\n'), [&](const auto &line) {
            auto escaped = false;
            for (auto it = line.begin(); it != line.end(); ++it) {
                ++stringLiteralsCount;
                if (escaped) {
                    escaped = false;
                } else if (*it == '\\' && *std::next(it) == 'x') {
                    ++charactersInMemory;
                    stringLiteralsCount += 3;
                    it = std::next(it, 3);
                } else if (*it == '\\') {
                    ++charactersInMemory;
                    escaped = true;
                } else if (*it != '\"') {
                    ++charactersInMemory;
                }
            }
        });

        return stringLiteralsCount - charactersInMemory;
    }
}
