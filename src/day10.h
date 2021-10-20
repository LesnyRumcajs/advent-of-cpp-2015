#pragma once

#include <string_view>
#include <string>

namespace day10 {
    [[nodiscard]] auto playLookAndSay(std::string_view input, size_t count) -> std::string {
        auto result = std::string{input};

        auto newResult = std::string{};
        auto appendToResult = [](auto count, auto num, auto &result) {
            result += std::to_string(count);
            result.push_back(num);
        };

        while (count--) {
            newResult.clear();
            auto current = result.front();
            auto currentCount = 1;
            for (auto it = result.begin() + 1; it != result.end(); ++it) {
                if (*it == current) {
                    ++currentCount;
                } else {
                    appendToResult(currentCount, current, newResult);
                    currentCount = 1;
                    current = *it;
                }
            }
            appendToResult(currentCount, current, newResult);
            result = newResult;
        }

        return result;
    }
}
